#!/bin/bash

# Deployment script of Drupal Pilipinas
# Created by Gerald Villorente

usage() {
  echo "Ex: ./deployment.sh local|staging"
  exit 1
}

if [ -z "$1" ]; then
  echo "You have to specify the environment."
  echo "";
  usage
  exit 1
fi

read -p "What is the name of the folder where your settings.php currently resides in? " SETTINGS_DIR

if [ ! -d "$SETTINGS_DIR" ]; then
  echo "The folder you specified doesn't exist. Get a coffee and run again."
  exit 1
fi
# Navigate to files/settings directory.
cd $SETTINGS_DIR

# Read the user input
read -p "Are you sure you want to deploy (Y/N)? " ANSWER

# Check if the user cofirmed. 
if [ -z "$ANSWER" ]; then
  echo "Oh crap! You have to agree matey."
  exit 1
else
  # Check for the supplied input.
  if [ "$ANSWER" == "Y" ]; then
  
    # Enable contrib modules.
    drush en ctools -y
    drush en entity -y
    drush en context -y
    # drush en delta -y
    # drush en delta_ui -y
    drush en drupinas_core -y
    drush en context_ui -y
    drush en features -y
    drush en browscap -y
    drush en token -y
    drush en pathauto -y
    drush en metatag -y
    drush en views -y
    drush en views_ui -y
    drush en ckeditor -y
    drush dis toolbar -y
    drush en strongarm -y
    drush en libraries -y
    drush en views_slideshow -y
    drush en views_slideshow_cycle -y
    drush en admin -y
    drush en webform -y
    drush en location -y
    drush en location_node -y
    drush en location_cck -y
    drush en location_entity -y
    drush en location_search -y
    drush en location_user -y
    drush en select_or_other -y
    drush en date_api -y
    drush en date -y
    drush en date_popup -y
    drush en date_views -y
    drush en calendar -y
    drush en diff -y
    drush en contact -y
    drush en link -y
    drush en oembedcore -y
    drush en oembedfield -y
    drush en field_group -y
    
    # Profile
    drush en profile2 -y
    drush en profile2_page -y
    
    # Q & A
    drush en entityreference -y
    drush en references -y
    drush en eva -y
    drush en node_reference -y 
    drush en nodereference_count -y
    drush en nodereference_url -y
    drush en answers -y
    
    # Mapping
    drush en geophp -y
    drush en geofield -y
    drush en geofield_map -y
    drush en leaflet -y
    drush en leaflet_views -y
    drush en leaflet_more_maps -y
    drush en openlayers -y
    drush en openlayers_ui -y
    
    # Voting API
    drush en votingapi -y
    drush en rate -y
    
    # Theme.
    drush en drupalpilipinas -y
    drush vset theme_default drupalpilipinas 1

    # Features.
    drush en hero -y
    drush en drupinas_global_settings -y
    drush en article -y
    drush en slideshow -y
    drush en drupinas_menu -y
    drush en drupinas_context -y
    drush en featured_blog -y
    drush en events -y
    drush en jobs -y
    drush en question_and_answer -y
    drush en drupinasblog -y
    drush en drupinas_profile -y
    
    # QnA
    drush en recent_questions -y

    # Run update.php
    # Reset Features.
    # Force to clear the cache.
    drush updb -y
    drush fra -y
    drush cc all

    echo "All deployed. Thank you!"

    exit 1
  elif [ "$ANSWER" == "N" ]; then
    echo "Don't be afraid, everythings gonna be alright. Lagot ka!"
    exit 1
  elif [ "$ANSWER" != "Y" ] || [ "$ANSWER" -ne "N" ]; then
    echo "I only accept Y or N! Cmmon! Looseerr!"
    exit 1
  fi 
fi
