#!/bin/bash

# Go to docroot/
cd docroot/

# Drop all tables (including non-drupal)
drush sql-drop -y
ecode=$?
if [ ${ecode} != 0 ]; then
  echo "Error cleaning database"
  exit ${ecode};
fi

# Load the local dump
cat ../../source-dump.sql | mysql -h php-mysql -u jenkins --password=jenkins jenkins_osha
ecode=$?
if [ ${ecode} != 0 ]; then
  echo "Error loading SQL dump into database"
  exit ${ecode};
fi

# Devify the installation
drush -y devify
ecode=$?
if [ ${ecode} != 0 ]; then
  echo "Devify has returned an error"
  exit ${ecode};
fi

# Devify the installation
drush devify_solr
ecode=$?
if [ ${ecode} != 0 ]; then
  echo "Devify Solr has returned an error"
  exit ${ecode};
fi

# Build the site
drush osha_build -y
ecode=$?
if [ ${ecode} != 0 ]; then
  echo "osha_build has returned an error"
  exit ${ecode};
fi

drush fl | grep -i overridden > /dev/null 2>&1
c=$?
if [ ${c} == 0 ]; then
  echo "Found overriden features after rebuild, failing ..."
  exit -1
fi
