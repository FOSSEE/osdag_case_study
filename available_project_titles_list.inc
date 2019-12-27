<?php
// case study display completed proposals
function list_of_available_project_titles()
{
	$output = "";
	$static_url = "https://static.fossee.in/cfd/project-titles/";
	$preference_rows = array();
		$i = 1;
	$query = db_query("SELECT * from list_of_project_titles WHERE {project_title_name} NOT IN( SELECT  project_title from case_study_proposal WHERE approval_status = 0 OR approval_status = 1 OR approval_status = 3)");
	while($result = $query->fetchObject()) {
		$preference_rows[] = array(
				$i,
				//print_r(array_keys($case_studies_list))
				l($result->project_title_name, $static_url . $result->filepath, array(
			    'external' => TRUE,
			    'attributes' => array(
			      'target'=> '_blank',
			    ),
			  ))
				);
			$i++;
	}
		$preference_header = array(
			'No',
			'List of available projects'
		);
		$output .= theme('table', array(
			'header' => $preference_header,
			'rows' => $preference_rows
		));
	
	return $output;
}