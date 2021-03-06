<?php

/**
 * Implements hook_pathauto_punctuation_chars_alter().
 */
function osha_pathauto_punctuation_chars_alter(array &$punctuation) {
  // Add the trademark symbol.
  $punctuation['trademark'] = array('value' => '™', 'name' => t('Trademark symbol'));
  $punctuation['U+00BF'] = array('value' => '¿', 'name' => t('Inverted Question Mark'));
  $punctuation['U+00B8'] = array('value' => '¸', 'name' => t('Cedilla'));
  $punctuation['U+00B7'] = array('value' => '·', 'name' => t('Middle dot'));
  $punctuation['U+00A8'] = array('value' => '¨', 'name' => t('Diaeresis'));
  $punctuation['U+00B4'] = array('value' => '´', 'name' => t('Acute accent'));
  $punctuation['8222'] = array('value' => '„', 'name' => t('Quote open'));
  $punctuation['8220'] = array('value' => '“', 'name' => t('Quote close'));
  $punctuation['8218'] = array('value' => '‚', 'name' => t('Single quote open'));
  $punctuation['8216'] = array('value' => '‘', 'name' => t('Single quote close'));
  $punctuation['8249'] = array('value' => '‹', 'name' => t('Single chevron close'));
  $punctuation['8250'] = array('value' => '›', 'name' => t('Single chevron close'));
  $punctuation['0171'] = array('value' => '«', 'name' => t('Double chevron open'));
  $punctuation['0187'] = array('value' => '»', 'name' => t('Double chevron close'));
  $punctuation['en-dash'] = array('value' => '–', 'name' => t('En dash'));
  $punctuation['em-dash'] = array('value' => '—', 'name' => t('Em dash'));
  $punctuation['apostrophe'] = array('value' => '’', 'name' => t('Apostrophe'));
  $punctuation['double-exclamation-mark'] = array('value' => '‼', 'name' => t('Double exclamation mark'));
  $punctuation['overline'] = array('value' => '‾', 'name' => t('Overline'));
  $punctuation['U+2026'] = array('value' => '…', 'name' => t('Horizontal ellipsis'));
  $punctuation['U+2021'] = array('value' => '”', 'name' => t('RIGHT DOUBLE QUOTATION MARK'));
}

/**
 * Implements hook_pathauto_alias_alter().
 */
function osha_pathauto_alias_alter(&$alias, array &$context) {
  $replace = _osha_pathauto_special_char_replacements();
  $search = array_keys($replace);
  $alias = str_replace($search, $replace, $alias);
}

/**
 * List of special chars replacements.
 */
function _osha_pathauto_special_char_replacements() {
  return array(
    'À' => 'A',
    'Á' => 'A',
    'Â' => 'A',
    'Ã' => 'A',
    'Ä' => 'A',
    'Å' => 'A',
    'Ç' => 'C',
    'È' => 'E',
    'É' => 'E',
    'Ê' => 'E',
    'Ë' => 'E',
    'Ì' => 'I',
    'Í' => 'I',
    'Î' => 'I',
    'Ï' => 'I',
    'Ñ' => 'N',
    'Ò' => 'O',
    'Ó' => 'O',
    'Ô' => 'O',
    'Õ' => 'O',
    'Ö' => 'O',
    'Ù' => 'U',
    'Ú' => 'U',
    'Û' => 'U',
    'Ü' => 'U',
    'Ý' => 'Y',
    'ß' => 's',
    'à' => 'a',
    'á' => 'a',
    'â' => 'a',
    'ã' => 'a',
    'ä' => 'a',
    'å' => 'a',
    'ç' => 'c',
    'è' => 'e',
    'é' => 'e',
    'ê' => 'e',
    'ë' => 'e',
    'ì' => 'i',
    'í' => 'i',
    'î' => 'i',
    'ï' => 'i',
    'ñ' => 'n',
    'ò' => 'o',
    'ó' => 'o',
    'ô' => 'o',
    'õ' => 'o',
    'ö' => 'o',
    'ù' => 'u',
    'ú' => 'u',
    'û' => 'u',
    'ü' => 'u',
    'ý' => 'y',
    'ÿ' => 'y',
    'Ā' => 'A',
    'ā' => 'a',
    'Ă' => 'A',
    'ă' => 'a',
    'Ą' => 'A',
    'ą' => 'a',
    'Ć' => 'C',
    'ć' => 'c',
    'Ĉ' => 'C',
    'ĉ' => 'c',
    'Ċ' => 'C',
    'ċ' => 'c',
    'Č' => 'C',
    'č' => 'c',
    'Ď' => 'D',
    'ď' => 'd',
    'Đ' => 'D',
    'đ' => 'd',
    'Ē' => 'E',
    'ē' => 'e',
    'Ĕ' => 'E',
    'ĕ' => 'e',
    'Ė' => 'E',
    'ė' => 'e',
    'Ę' => 'E',
    'ę' => 'e',
    'Ě' => 'E',
    'ě' => 'e',
    'Ĝ' => 'G',
    'ĝ' => 'g',
    'Ğ' => 'G',
    'ğ' => 'g',
    'Ġ' => 'G',
    'ġ' => 'g',
    'Ģ' => 'G',
    'ģ' => 'g',
    'Ĥ' => 'H',
    'ĥ' => 'h',
    'Ħ' => 'H',
    'ħ' => 'h',
    'Ĩ' => 'I',
    'ĩ' => 'i',
    'Ī' => 'I',
    'ī' => 'i',
    'Ĭ' => 'I',
    'ĭ' => 'i',
    'Į' => 'I',
    'į' => 'i',
    'İ' => 'I',
    'ı' => 'i',
    'Ĳ' => 'IJ',
    'ĳ' => 'ij',
    'Ĵ' => 'J',
    'ĵ' => 'j',
    'Ķ' => 'K',
    'ķ' => 'k',
    'ĸ' => 'k',
    'Ĺ' => 'L',
    'ĺ' => 'l',
    'Ļ' => 'L',
    'ļ' => 'l',
    'Ľ' => 'L',
    'ľ' => 'l',
    'Ŀ' => 'L',
    'ŀ' => 'l',
    'Ł' => 'L',
    'ł' => 'l',
    'Ń' => 'N',
    'ń' => 'n',
    'Ņ' => 'N',
    'ņ' => 'n',
    'Ň' => 'N',
    'ň' => 'n',
    'ŉ' => 'N',
    'Ŋ' => 'n',
    'ŋ' => 'N',
    'Ō' => 'O',
    'ō' => 'o',
    'Ŏ' => 'O',
    'ŏ' => 'o',
    'Ő' => 'O',
    'ő' => 'o',
    'Œ' => 'OE',
    'œ' => 'oe',
    'Ŕ' => 'R',
    'ŕ' => 'r',
    'Ŗ' => 'R',
    'ŗ' => 'r',
    'Ř' => 'R',
    'ř' => 'r',
    'Ś' => 'S',
    'ś' => 's',
    'Ŝ' => 'S',
    'ŝ' => 's',
    'Ş' => 'S',
    'ş' => 's',
    'Š' => 'S',
    'š' => 's',
    'ș' => 's',
    'Ș' => 'S',
    'Ţ' => 'T',
    'ţ' => 't',
    'Ț' => 'T',
    'ț' => 't',
    'Ť' => 'T',
    'ť' => 't',
    'Ŧ' => 'T',
    'ŧ' => 't',
    'Ũ' => 'U',
    'ũ' => 'u',
    'Ū' => 'U',
    'ū' => 'u',
    'Ŭ' => 'U',
    'ŭ' => 'u',
    'Ů' => 'U',
    'ů' => 'u',
    'Ű' => 'U',
    'ű' => 'u',
    'Ų' => 'U',
    'ų' => 'u',
    'Ŵ' => 'W',
    'ŵ' => 'w',
    'Ŷ' => 'Y',
    'ŷ' => 'y',
    'Ÿ' => 'Y',
    'Ź' => 'Z',
    'ź' => 'z',
    'Ż' => 'Z',
    'ż' => 'z',
    'Ž' => 'Z',
    'ž' => 'z',
    'ſ' => 's',
  );
}
