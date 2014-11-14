Overview
--------
This module is an add-on for the Apache Solr Search Integration module
(http://drupal.org/project/apachesolr).
It will make it possible to index info from a location field 
http://drupal.org/project/location (city, zip, province, country
and coordinates) into a SOLR index. Additionally it provides
extra facets for city, zip, province and country.

In the future I want to provide a geospatial search block, that will use the
indexed coordinates. That way you'll be able to provide a city and radius.
The city will be translated to coordinates and SOLR will return all items within
that reach.

Features
--------
- Indexing of information in a location field in SOLR (city, zip, province,
country)
- You get facets for the indexed information of the location field (city, zip,
province, country)
- Indexing of the coordinates of the location in SOLR. This will make it
possible to do geospatial search with SOLR.

Future features
- I want to add a basic search block (you can enable) to do geospatial search.
- I want to add an advance block (you can enable) to do geospatial search with a
visual map.
- For the moment only location fields on nodes get indexed, I would like to make
it possible to index a location field on any entity.

Requirements
------------
To make use of this module you need these modules:
- Apache SOLR search integration (http://drupal.org/project/apachesolr)
- Location (http://drupal.org/project/location)

And you need a SOLR server. Nick_vh (http://drupal.org/user/122682) has a good
tutorial 
(http://www.nickveenhof.be/blog/simple-guide-install-apache-solr-3x-drupal-7) on
installing SOLR on your local machine.
Once these requirements are met, you can configure the connection with the SOLR
server & configure the facets on your search page, add a content type with a
location field, create some nodes. Then you can start indexing your content.
Go to the search page and you'll be able to search your nodes and filter the
location facets.
