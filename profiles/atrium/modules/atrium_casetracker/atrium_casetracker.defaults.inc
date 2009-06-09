<?php

/**
 * Helper to implemetation of hook_context_default_contexts().
 */
function _atrium_casetracker_context_default_contexts() {
  $items = array();

  $items[] = array(
    'namespace' => 'spaces',
    'attribute' => 'feature',
    'value' => 'casetracker',
    'node' => array(
      '0' => 'casetracker_basic_case',
      '1' => 'casetracker_basic_project',
    ),
    'menu' => 'casetracker',
    'views' => array(
      '0' => 'atrium_casetracker',
      '1' => 'atrium_casetracker_projects',
    ),
    'spaces' => array(
      'label' => 'Casetracker',
      'description' => 'Provides an issue and task tracker',
      'menu' => array(
        '0' => array(
          'title' => 'Casetracker',
          'href' => 'casetracker',
        ),
      ),
      'types' => array(
        '0' => 'og',
        '1' => 'user',
      ),
    ),
    'block' => array(
      'atrium_casetracker-book' => array(
        'module' => 'atrium_casetracker',
        'delta' => 'book',
        'weight' => -13,
        'region' => 'right',
      ),
      'atrium_casetracker-filters' => array(
        'module' => 'atrium_casetracker',
        'delta' => 'filters',
        'weight' => -12,
        'region' => 'right',
      ),
      'views_atrium_casetracker-block_2' => array(
        'module' => 'views',
        'delta' => 'atrium_casetracker-block_2',
        'weight' => -11,
        'region' => 'right',
      ),
      'views-atrium_casetracker-block_1' => array(
        'module' => 'views',
        'delta' => 'atrium_casetracker-block_1',
        'weight' => 11,
        'region' => 'content',
      ),
    ),
  );
  return $items;
}

/**
 * Helper to implemetation of hook_menu_default_items().
 */
function _atrium_casetracker_menu_default_items() {
  $items = array();

  $items[] = array(
    'title' => 'Casetracker',
    'path' => 'casetracker',
    'weight' => '0',
    'description' => 'Provides a casetracker feature',
  );

  return $items;
}

/**
 * Helper to implemetation of hook_views_default_views().
 */
function _atrium_casetracker_views_default_views() {
  $views = array();

  // Exported view: atrium_casetracker
  $view = new view;
  $view->name = 'atrium_casetracker';
  $view->description = 'Atrium > Casetracker';
  $view->tag = 'atrium';
  $view->view_php = '';
  $view->base_table = 'node';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('relationships', array(
    'pid' => array(
      'label' => 'project',
      'required' => 0,
      'id' => 'pid',
      'table' => 'casetracker_case',
      'field' => 'pid',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('fields', array(
    'pid' => array(
      'label' => 'Project',
      'exclude' => 0,
      'id' => 'pid',
      'table' => 'casetracker_case',
      'field' => 'pid',
      'relationship' => 'none',
    ),
    'case_priority_id' => array(
      'label' => 'Priority',
      'exclude' => 0,
      'id' => 'case_priority_id',
      'table' => 'casetracker_case',
      'field' => 'case_priority_id',
      'relationship' => 'none',
    ),
    'timestamp' => array(
      'label' => 'New',
      'link_to_node' => 0,
      'comments' => 0,
      'exclude' => 0,
      'id' => 'timestamp',
      'table' => 'history_user',
      'field' => 'timestamp',
      'relationship' => 'none',
    ),
    'title' => array(
      'label' => 'Title',
      'link_to_node' => 1,
      'exclude' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'none',
    ),
    'assign_to' => array(
      'label' => 'Assigned',
      'exclude' => 0,
      'id' => 'assign_to',
      'table' => 'casetracker_case',
      'field' => 'assign_to',
      'relationship' => 'none',
    ),
    'case_status_id' => array(
      'label' => 'Status',
      'exclude' => 0,
      'id' => 'case_status_id',
      'table' => 'casetracker_case',
      'field' => 'case_status_id',
      'relationship' => 'none',
    ),
    'last_updated' => array(
      'label' => 'Last post',
      'date_format' => 'reldate',
      'custom_date_format' => '',
      'exclude' => 0,
      'id' => 'last_updated',
      'table' => 'node_comment_statistics',
      'field' => 'last_updated',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('sorts', array(
    'case_status_id' => array(
      'order' => 'ASC',
      'id' => 'case_status_id',
      'table' => 'casetracker_case',
      'field' => 'case_status_id',
      'relationship' => 'none',
    ),
    'last_updated' => array(
      'order' => 'DESC',
      'granularity' => 'second',
      'id' => 'last_updated',
      'table' => 'node_comment_statistics',
      'field' => 'last_updated',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('filters', array(
    'case' => array(
      'operator' => '=',
      'value' => '',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'case',
      'table' => 'node',
      'field' => 'case',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
    'status' => array(
      'operator' => '=',
      'value' => 1,
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'status',
      'table' => 'node',
      'field' => 'status',
      'relationship' => 'none',
    ),
    'status_1' => array(
      'operator' => '=',
      'value' => 1,
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'status_1',
      'table' => 'node',
      'field' => 'status',
      'relationship' => 'pid',
    ),
    'current' => array(
      'operator' => 'all',
      'value' => 'all',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'current',
      'table' => 'spaces',
      'field' => 'current',
      'relationship' => 'none',
    ),
    'keys' => array(
      'operator' => 'optional',
      'value' => '',
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'use_operator' => 0,
        'operator' => 'keys_op',
        'identifier' => 'keys',
        'label' => 'Search',
        'optional' => 1,
        'remember' => 0,
      ),
      'id' => 'keys',
      'table' => 'search_index',
      'field' => 'keys',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'pid' => array(
      'operator' => 'or',
      'value' => array(),
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'use_operator' => 0,
        'operator' => 'pid_op',
        'identifier' => 'pid',
        'label' => 'Project',
        'optional' => 1,
        'single' => 1,
        'remember' => 0,
        'reduce' => 0,
      ),
      'id' => 'pid',
      'table' => 'casetracker_case',
      'field' => 'pid',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
      'reduce_duplicates' => 0,
    ),
    'case_priority_id' => array(
      'operator' => 'or',
      'value' => array(),
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'use_operator' => 0,
        'operator' => 'case_priority_id_op',
        'identifier' => 'case_priority_id',
        'label' => 'Priority',
        'optional' => 1,
        'single' => 1,
        'remember' => 0,
        'reduce' => 0,
      ),
      'id' => 'case_priority_id',
      'table' => 'casetracker_case',
      'field' => 'case_priority_id',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
      'reduce_duplicates' => 0,
    ),
    'case_status_id' => array(
      'operator' => 'or',
      'value' => array(),
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'use_operator' => 0,
        'operator' => 'case_status_id_op',
        'identifier' => 'case_status_id',
        'label' => 'Status',
        'optional' => 1,
        'single' => 1,
        'remember' => 0,
        'reduce' => 0,
      ),
      'id' => 'case_status_id',
      'table' => 'casetracker_case',
      'field' => 'case_status_id',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
      'reduce_duplicates' => 0,
    ),
    'case_status_closed' => array(
      'operator' => '=',
      'value' => '0',
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'operator' => '',
        'identifier' => 'case_status_closed',
        'label' => 'Show closed cases',
        'optional' => 0,
        'remember' => 0,
      ),
      'id' => 'case_status_closed',
      'table' => 'casetracker_case2',
      'field' => 'case_status_closed',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'spaces_feature',
    'spaces_feature' => 'atrium_casetracker',
  ));
  $handler->override_option('title', 'All cases');
  $handler->override_option('empty', 'No cases found.');
  $handler->override_option('items_per_page', 25);
  $handler->override_option('use_pager', '1');
  $handler->override_option('style_plugin', 'table');
  $handler->override_option('style_options', array(
    'grouping' => '',
    'override' => 0,
    'sticky' => 0,
    'order' => 'desc',
    'columns' => array(
      'pid' => 'case_priority_id',
      'case_priority_id' => 'case_priority_id',
      'title' => 'title',
      'timestamp' => 'title',
      'assign_to' => 'assign_to',
      'case_status_id' => 'case_status_id',
      'last_updated' => 'last_updated',
    ),
    'info' => array(
      'pid' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'case_priority_id' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'title' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'timestamp' => array(
        'separator' => '',
      ),
      'assign_to' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'case_status_id' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'last_updated' => array(
        'sortable' => 1,
        'separator' => '',
      ),
    ),
    'default' => '-1',
  ));
  $handler = $view->new_display('page', 'All cases', 'page_1');
  $handler->override_option('filters', array(
    'case' => array(
      'operator' => '=',
      'value' => '',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'case',
      'table' => 'node',
      'field' => 'case',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
    'status' => array(
      'operator' => '=',
      'value' => 1,
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'status',
      'table' => 'node',
      'field' => 'status',
      'relationship' => 'none',
    ),
    'status_1' => array(
      'operator' => '=',
      'value' => 1,
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'status_1',
      'table' => 'node',
      'field' => 'status',
      'relationship' => 'pid',
    ),
    'keys' => array(
      'operator' => 'optional',
      'value' => '',
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'use_operator' => 0,
        'operator' => 'keys_op',
        'identifier' => 'keys',
        'label' => 'Search',
        'optional' => 1,
        'remember' => 0,
      ),
      'id' => 'keys',
      'table' => 'search_index',
      'field' => 'keys',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
    'assign_to' => array(
      'operator' => 'or',
      'value' => array(),
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'use_operator' => 0,
        'operator' => 'assign_to_op',
        'identifier' => 'assign_to',
        'label' => 'Assigned',
        'optional' => 1,
        'single' => 0,
        'remember' => 0,
        'reduce' => 0,
      ),
      'id' => 'assign_to',
      'table' => 'casetracker_case',
      'field' => 'assign_to',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
      'reduce_duplicates' => 0,
    ),
    'pid' => array(
      'operator' => 'or',
      'value' => array(),
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'use_operator' => 0,
        'operator' => 'pid_op',
        'identifier' => 'pid',
        'label' => 'Project',
        'optional' => 1,
        'single' => 1,
        'remember' => 0,
        'reduce' => 0,
      ),
      'id' => 'pid',
      'table' => 'casetracker_case',
      'field' => 'pid',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
      'reduce_duplicates' => 0,
    ),
    'case_priority_id' => array(
      'operator' => 'or',
      'value' => array(),
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'use_operator' => 0,
        'operator' => 'case_priority_id_op',
        'identifier' => 'case_priority_id',
        'label' => 'Priority',
        'optional' => 1,
        'single' => 1,
        'remember' => 0,
        'reduce' => 0,
      ),
      'id' => 'case_priority_id',
      'table' => 'casetracker_case',
      'field' => 'case_priority_id',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
      'reduce_duplicates' => 0,
    ),
    'case_status_id' => array(
      'operator' => 'or',
      'value' => array(),
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'use_operator' => 0,
        'operator' => 'case_status_id_op',
        'identifier' => 'case_status_id',
        'label' => 'Status',
        'optional' => 1,
        'single' => 1,
        'remember' => 0,
        'reduce' => 0,
      ),
      'id' => 'case_status_id',
      'table' => 'casetracker_case',
      'field' => 'case_status_id',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
      'reduce_duplicates' => 0,
    ),
    'current' => array(
      'operator' => 'all',
      'value' => 'all',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'current',
      'table' => 'spaces',
      'field' => 'current',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
    'case_status_closed' => array(
      'operator' => '=',
      'value' => '0',
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'operator' => '',
        'identifier' => 'case_status_closed',
        'label' => 'Show closed cases',
        'optional' => 0,
        'remember' => 0,
      ),
      'id' => 'case_status_closed',
      'table' => 'casetracker_case2',
      'field' => 'case_status_closed',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('path', 'casetracker/filter');
  $handler->override_option('menu', array(
    'type' => 'default tab',
    'title' => 'All cases',
    'description' => '',
    'weight' => '-10',
    'name' => 'navigation',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'normal',
    'title' => 'Casetracker',
    'description' => '',
    'weight' => '0',
  ));
  $handler = $view->new_display('page', 'My cases', 'page_2');
  $handler->override_option('filters', array(
    'case' => array(
      'operator' => '=',
      'value' => '',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'case',
      'table' => 'node',
      'field' => 'case',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
    'status' => array(
      'operator' => '=',
      'value' => 1,
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'status',
      'table' => 'node',
      'field' => 'status',
      'relationship' => 'none',
    ),
    'status_1' => array(
      'operator' => '=',
      'value' => 1,
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'status_1',
      'table' => 'node',
      'field' => 'status',
      'relationship' => 'pid',
    ),
    'current' => array(
      'operator' => 'all',
      'value' => 'all',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'current',
      'table' => 'spaces',
      'field' => 'current',
      'relationship' => 'none',
    ),
    'keys' => array(
      'operator' => 'optional',
      'value' => '',
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'use_operator' => 0,
        'operator' => 'keys_op',
        'identifier' => 'keys',
        'label' => 'Search',
        'optional' => 1,
        'remember' => 0,
      ),
      'id' => 'keys',
      'table' => 'search_index',
      'field' => 'keys',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'pid' => array(
      'operator' => 'or',
      'value' => array(),
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'use_operator' => 0,
        'operator' => 'pid_op',
        'identifier' => 'pid',
        'label' => 'Project',
        'optional' => 1,
        'single' => 1,
        'remember' => 0,
        'reduce' => 0,
      ),
      'id' => 'pid',
      'table' => 'casetracker_case',
      'field' => 'pid',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
      'reduce_duplicates' => 0,
    ),
    'case_priority_id' => array(
      'operator' => 'or',
      'value' => array(),
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'use_operator' => 0,
        'operator' => 'case_priority_id_op',
        'identifier' => 'case_priority_id',
        'label' => 'Priority',
        'optional' => 1,
        'single' => 1,
        'remember' => 0,
        'reduce' => 0,
      ),
      'id' => 'case_priority_id',
      'table' => 'casetracker_case',
      'field' => 'case_priority_id',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
      'reduce_duplicates' => 0,
    ),
    'case_status_id' => array(
      'operator' => 'or',
      'value' => array(),
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'use_operator' => 0,
        'operator' => 'case_status_id_op',
        'identifier' => 'case_status_id',
        'label' => 'Status',
        'optional' => 1,
        'single' => 1,
        'remember' => 0,
        'reduce' => 0,
      ),
      'id' => 'case_status_id',
      'table' => 'casetracker_case',
      'field' => 'case_status_id',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
      'reduce_duplicates' => 0,
    ),
    'assign_to' => array(
      'operator' => 'or',
      'value' => array(
        '***CURRENT_USER***' => '***CURRENT_USER***',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'assign_to',
      'table' => 'casetracker_case',
      'field' => 'assign_to',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
      'reduce_duplicates' => 0,
    ),
    'case_status_closed' => array(
      'operator' => '=',
      'value' => '0',
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'operator' => '',
        'identifier' => 'case_status_closed',
        'label' => 'Show closed cases',
        'optional' => 0,
        'remember' => 0,
      ),
      'id' => 'case_status_closed',
      'table' => 'casetracker_case2',
      'field' => 'case_status_closed',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('title', 'My cases');
  $handler->override_option('empty', 'There are no cases assigned to you.');
  $handler->override_option('path', 'casetracker/mycases');
  $handler->override_option('menu', array(
    'type' => 'tab',
    'title' => 'My cases',
    'description' => '',
    'weight' => '0',
    'name' => 'navigation',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'normal',
    'title' => 'Casetracker',
    'description' => '',
    'weight' => '0',
  ));
  $handler = $view->new_display('page', 'Project cases', 'page_3');
  $handler->override_option('arguments', array(
    'nid' => array(
      'default_action' => 'not found',
      'style_plugin' => 'default_summary',
      'style_options' => array(),
      'wildcard' => 'all',
      'wildcard_substitution' => 'All',
      'title' => '',
      'default_argument_type' => 'fixed',
      'default_argument' => '',
      'validate_type' => 'node',
      'validate_fail' => 'not found',
      'break_phrase' => 0,
      'not' => 0,
      'id' => 'nid',
      'table' => 'node',
      'field' => 'nid',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'pid',
      'default_options_div_prefix' => '',
      'default_argument_user' => 0,
      'default_argument_fixed' => '',
      'default_argument_php' => '',
      'validate_argument_node_type' => array(
        'casetracker_basic_project' => 'casetracker_basic_project',
        'blog' => 0,
        'casetracker_basic_case' => 0,
        'shoutbox' => 0,
        'admin_message' => 0,
        'book' => 0,
        'event' => 0,
        'feedapi_node' => 0,
        'feed_ical' => 0,
        'feed_ical_item' => 0,
        'group' => 0,
        'imageset' => 0,
        'page' => 0,
        'profile' => 0,
        'project_book' => 0,
      ),
      'validate_argument_node_access' => 1,
      'validate_argument_nid_type' => 'nid',
      'validate_argument_vocabulary' => array(
        '5' => 0,
        '1' => 0,
        '2' => 0,
        '6' => 0,
        '4' => 0,
      ),
      'validate_argument_type' => 'tid',
      'user_argument_type' => '',
      'restrict_user_roles' => 0,
      'user_roles' => array(),
      'validate_argument_is_member' => 0,
      'validate_argument_php' => '',
    ),
  ));
  $handler->override_option('filters', array(
    'case' => array(
      'operator' => '=',
      'value' => '',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'case',
      'table' => 'node',
      'field' => 'case',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
    'status' => array(
      'operator' => '=',
      'value' => 1,
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'status',
      'table' => 'node',
      'field' => 'status',
      'relationship' => 'none',
    ),
    'status_1' => array(
      'operator' => '=',
      'value' => 1,
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'status_1',
      'table' => 'node',
      'field' => 'status',
      'relationship' => 'pid',
    ),
    'current' => array(
      'operator' => 'all',
      'value' => 'all',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'current',
      'table' => 'spaces',
      'field' => 'current',
      'relationship' => 'none',
    ),
    'keys' => array(
      'operator' => 'optional',
      'value' => '',
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'use_operator' => 0,
        'operator' => 'keys_op',
        'identifier' => 'keys',
        'label' => 'Search',
        'optional' => 1,
        'remember' => 0,
      ),
      'id' => 'keys',
      'table' => 'search_index',
      'field' => 'keys',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'case_priority_id' => array(
      'operator' => 'or',
      'value' => array(),
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'use_operator' => 0,
        'operator' => 'case_priority_id_op',
        'identifier' => 'case_priority_id',
        'label' => 'Priority',
        'optional' => 1,
        'single' => 1,
        'remember' => 0,
        'reduce' => 0,
      ),
      'id' => 'case_priority_id',
      'table' => 'casetracker_case',
      'field' => 'case_priority_id',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
      'reduce_duplicates' => 0,
    ),
    'case_status_id' => array(
      'operator' => 'or',
      'value' => array(),
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'use_operator' => 0,
        'operator' => 'case_status_id_op',
        'identifier' => 'case_status_id',
        'label' => 'Status',
        'optional' => 1,
        'single' => 1,
        'remember' => 0,
        'reduce' => 0,
      ),
      'id' => 'case_status_id',
      'table' => 'casetracker_case',
      'field' => 'case_status_id',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
      'reduce_duplicates' => 0,
    ),
    'case_status_closed' => array(
      'operator' => '=',
      'value' => '0',
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'operator' => '',
        'identifier' => 'case_status_closed',
        'label' => 'Show closed cases',
        'optional' => 0,
        'remember' => 0,
      ),
      'id' => 'case_status_closed',
      'table' => 'casetracker_case2',
      'field' => 'case_status_closed',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('path', 'node/%/casetracker');
  $handler->override_option('menu', array(
    'type' => 'tab',
    'title' => 'Cases',
    'description' => '',
    'weight' => '0',
    'name' => 'navigation',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
  ));
  $handler = $view->new_display('block', 'Project cases (newest)', 'block_1');
  $handler->override_option('arguments', array(
    'nid' => array(
      'default_action' => 'default',
      'style_plugin' => 'default_summary',
      'style_options' => array(),
      'wildcard' => 'all',
      'wildcard_substitution' => 'All',
      'title' => '',
      'default_argument_type' => 'php',
      'default_argument' => '',
      'validate_type' => 'node',
      'validate_fail' => 'not found',
      'break_phrase' => 0,
      'not' => 0,
      'id' => 'nid',
      'table' => 'node',
      'field' => 'nid',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'pid',
      'default_options_div_prefix' => '',
      'default_argument_user' => 0,
      'default_argument_fixed' => '',
      'default_argument_php' => 'if ($node = menu_get_object()) {
                          return $node->nid;
                        }',
      'validate_argument_node_type' => array(
        'casetracker_basic_project' => 'casetracker_basic_project',
        'blog' => 0,
        'casetracker_basic_case' => 0,
        'shoutbox' => 0,
        'admin_message' => 0,
        'book' => 0,
        'event' => 0,
        'feedapi_node' => 0,
        'feed_ical' => 0,
        'feed_ical_item' => 0,
        'group' => 0,
        'imageset' => 0,
        'page' => 0,
        'profile' => 0,
        'project_book' => 0,
      ),
      'validate_argument_node_access' => 1,
      'validate_argument_nid_type' => 'nid',
      'validate_argument_vocabulary' => array(
        '5' => 0,
        '1' => 0,
        '2' => 0,
        '6' => 0,
        '4' => 0,
      ),
      'validate_argument_type' => 'tid',
      'user_argument_type' => '',
      'restrict_user_roles' => 0,
      'user_roles' => array(),
      'validate_argument_is_member' => 0,
      'validate_argument_php' => '',
    ),
  ));
  $handler->override_option('title', 'Newest cases');
  $handler->override_option('items_per_page', 10);
  $handler->override_option('use_pager', '0');
  $handler->override_option('use_more', 1);
  $handler->override_option('link_display', 'page_3');
  $handler->override_option('block_description', '');
  $handler->override_option('block_caching', -1);
  $handler = $view->new_display('block', 'My cases', 'block_2');
  $handler->override_option('fields', array(
    'name' => array(
      'label' => '',
      'link_to_user' => 1,
      'exclude' => 0,
      'id' => 'name',
      'table' => 'users',
      'field' => 'name',
      'relationship' => 'none',
    ),
    'last_updated' => array(
      'label' => '',
      'date_format' => 'reldate',
      'custom_date_format' => '',
      'exclude' => 0,
      'id' => 'last_updated',
      'table' => 'node_comment_statistics',
      'field' => 'last_updated',
      'relationship' => 'none',
    ),
    'title' => array(
      'label' => '',
      'link_to_node' => 1,
      'exclude' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('filters', array(
    'assign_to' => array(
      'operator' => 'or',
      'value' => array(
        '***CURRENT_USER***' => '***CURRENT_USER***',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'assign_to',
      'table' => 'casetracker_case',
      'field' => 'assign_to',
      'relationship' => 'none',
      'reduce_duplicates' => 0,
    ),
    'last_comment_timestamp' => array(
      'operator' => '>=',
      'value' => array(
        'type' => 'offset',
        'value' => '-30 days',
        'min' => '',
        'max' => '',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'last_comment_timestamp',
      'table' => 'node_comment_statistics',
      'field' => 'last_comment_timestamp',
      'relationship' => 'none',
    ),
    'status' => array(
      'operator' => '=',
      'value' => 1,
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'status',
      'table' => 'node',
      'field' => 'status',
      'relationship' => 'none',
    ),
    'current' => array(
      'operator' => 'active',
      'value' => 'og',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'current',
      'table' => 'spaces',
      'field' => 'current',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('title', 'My cases');
  $handler->override_option('items_per_page', 5);
  $handler->override_option('use_pager', '0');
  $handler->override_option('style_plugin', 'list');
  $handler->override_option('block_description', '');
  $handler->override_option('block_caching', -1);
  $translatables['atrium_casetracker'] = array(
    t('Defaults'),
    t('All cases'),
    t('No cases found.'),
    t('My cases'),
    t('There are no cases assigned to you.'),
    t('Project cases'),
    t('Project cases (newest)'),
    t('Newest cases'),
  );

  $views[$view->name] = $view;

  // Exported view: atrium_casetracker_projects
  $view = new view;
  $view->name = 'atrium_casetracker_projects';
  $view->description = 'Atrium > Casetracker projects';
  $view->tag = 'atrium';
  $view->view_php = '';
  $view->base_table = 'node';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('fields', array(
    'title' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
      ),
      'link_to_node' => 1,
      'exclude' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'none',
    ),
    'case_count' => array(
      'label' => 'Open cases:',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
      ),
      'type' => 'status-6',
      'exclude' => 0,
      'set_precision' => FALSE,
      'precision' => 0,
      'decimal' => '.',
      'separator' => ',',
      'prefix' => '',
      'suffix' => '',
      'id' => 'case_count',
      'table' => 'casetracker_case',
      'field' => 'case_count',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('sorts', array(
    'title' => array(
      'order' => 'ASC',
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('filters', array(
    'status' => array(
      'operator' => '=',
      'value' => 1,
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'status',
      'table' => 'node',
      'field' => 'status',
      'relationship' => 'none',
    ),
    'current' => array(
      'operator' => 'all',
      'value' => 'all',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'current',
      'table' => 'spaces',
      'field' => 'current',
      'relationship' => 'none',
    ),
    'project' => array(
      'operator' => '=',
      'value' => '',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'project',
      'table' => 'node',
      'field' => 'project',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'spaces_feature',
    'spaces_feature' => 'atrium_casetracker',
  ));
  $handler->override_option('title', 'Projects');
  $handler->override_option('empty', 'No projects found.');
  $handler->override_option('items_per_page', 40);
  $handler->override_option('use_pager', '1');
  $handler->override_option('style_plugin', 'grid');
  $handler->override_option('style_options', array(
    'grouping' => '',
    'columns' => '2',
    'alignment' => 'vertical',
  ));
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->override_option('path', 'casetracker/projects');
  $handler->override_option('menu', array(
    'type' => 'tab',
    'title' => 'Projects',
    'description' => '',
    'weight' => '10',
    'name' => 'navigation',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
  ));
  $handler = $view->new_display('page', 'Archived projects', 'page_2');
  $handler->override_option('filters', array(
    'status' => array(
      'operator' => '=',
      'value' => 0,
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'status',
      'table' => 'node',
      'field' => 'status',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'project' => array(
      'operator' => '=',
      'value' => '',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'project',
      'table' => 'node',
      'field' => 'project',
      'relationship' => 'none',
    ),
    'current' => array(
      'operator' => 'all',
      'value' => 'all',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'current',
      'table' => 'spaces',
      'field' => 'current',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('title', 'Archived projects');
  $handler->override_option('empty', 'No archived projects found.');
  $handler->override_option('path', 'casetracker/archive');
  $handler->override_option('menu', array(
    'type' => 'tab',
    'title' => 'Archived',
    'description' => '',
    'weight' => '20',
    'name' => 'navigation',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
  ));
  $translatables['atrium_casetracker_projects'] = array(
    t('Defaults'),
    t('No projects found.'),
    t('Projects'),
    t('Page'),
    t('Archived projects'),
    t('No archived projects found.'),
  );

  $views[$view->name] = $view;

  return $views;
}