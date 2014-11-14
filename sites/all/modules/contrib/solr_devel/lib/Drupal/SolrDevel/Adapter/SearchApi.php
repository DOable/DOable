<?php

/**
 * @file
 * Contains Drupal_SolrDevel_SearchApi_Adapter.
 */

/**
 * Search API's implementation of the Solr Devel adapter.
 */
class Drupal_SolrDevel_Adapter_SearchApi extends Drupal_SolrDevel_Adapter {

  /**
   * Implements Drupal_SolrDevel_Adapter::searchByEntity().
   *
   * @todo Catch exceptions?
   */
  public function entityIndexed($entity_id, $entity_type = 'node') {
    $id = $this->getOption('index_name') . '-' . $entity_id;
    // Get Solr connection and do query here.
  }
}
