<table border="0" cellpadding="0" cellspacing="0" width="800" class="blue-line">
  <tbody>
    <tr>
      <td colspan="2" style="background-color:#003399; width:800px; height: 4px;" valign="top"></td>
    </tr>
  </tbody>
</table>

<table border="0" cellpadding="28" cellspacing="0" width="800" style="font-family: Oswald, Arial,sans-serif;">
  <tbody>
    <tr>
      <td>
        <?php
          $directory = drupal_get_path('module','osha_newsletter');
          global $base_url;
          global $language;
          print l(theme('image', array(
          'path' => $directory . '/images/Osha-EU-logos.png',
          'width' => 256,
          'height' => 60,
          'alt' => 'Osha logo',
          'attributes' => array('style' => 'border: 0px;')
          )), $base_url.'/'.$language->language, array(
          'html' => TRUE,
          'external' => TRUE
        ));
        ?>
      </td>
      <td>
        <div class="newsletter-number" style="color: #003399; font-size: 24px; font-weight: 300; text-align: right;"><?php print t('EU-OSHA news') ?></div>
      </td>
    </tr>
  </tbody>
</table>

<table border="0" cellpadding="28" cellspacing="0" width="800">
  <tbody>
    <tr>
      <td style="padding-top: 0px; padding-bottom: 0px;">
        <table border="0" cellpadding="0" cellspacing="0" width="100%">
          <tbody>
            <tr class="blue-line">
              <td style="background-color:#003399; width: 100%; height: 4px;"></td>
            </tr>

            <tr>
              <td>
                <table border="0" cellpadding="15" cellspacing="0" width="100%">
                  <tbody>
                    <tr>
                      <td style="font-size: 12px; padding-left: 30px; padding-right: 30px; font-family: Arial,sans-serif;">
                        <?php
                         if ($languages) {
                            $last_lang = array_pop($languages);
                            foreach ($languages as $l):?>
                              <a href="<?php echo url('node/' . $node_id, array('absolute' => TRUE, 'language' => $l));?>" style="text-decoration: none; color: #003399;">
                                <?php print $l->native . ' | ';?>
                              </a>
                            <?php  endforeach; ?>
                            <a href="<?php echo url('node/' . $node_id, array('absolute' => TRUE, 'language' => $last_lang));?>" style="text-decoration: none; color: #003399;">
                              <?php print $last_lang->native;?>
                            </a>
                         <?php
                         }
                        ?>
                      </td>
                    </tr>
                  </tbody>
                </table>
              </td>
            </tr>
            <tr class="blue-line">
              <td style="background-color:#003399; width: 100%; height: 4px;"></td>
            </tr>
          </tbody>
        </table>
      </td>
    </tr>
  </tbody>
</table>