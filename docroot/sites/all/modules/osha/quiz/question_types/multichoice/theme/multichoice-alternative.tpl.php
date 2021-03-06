<?php

/**
 * @file
 * Handles the layout of the multichoice answering form.
 *
 * Variables available:
 * - $form.
 */

// We want to have the checkbox in one table cell, and the title in the next.
// We store the checkbox and the titles.
$options = $form['user_answer']['#options'];
$fullOptions = array();
$titles = array();
foreach ($options as $key => $value) {
  $fullOptions[$key] = $form['user_answer'][$key];
  $titles[$key] = $form['user_answer'][$key]['#title'];
  $fullOptions[$key]['#title'] = '';
  unset($form['user_answer'][$key]);
}
unset($form['user_answer']['#options']);
print drupal_render_children($form);

// We use the stored checkboxes and titles to generate a table for the
// alternatives.
foreach ($titles as $key => $value) {
  $row = array();
  $row[] = array('data' => drupal_render($fullOptions[$key]), 'width' => 10);
  $row[] = $value;
  $rows[] = array('data' => $row, 'class' => array('multichoice-row'));
}
$tema = theme('table', array('header' => array(), 'rows' => $rows));
$tema = str_replace("<table>", "<table  style='width:100%' class='quiz-table'>", $tema);
print $tema;
