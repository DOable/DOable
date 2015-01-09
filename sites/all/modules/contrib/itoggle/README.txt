iToggle uses the iToggle jQuery plugin to create engaging and interactive widgets for fields and boolean bundle properties.

CONTENTS OF THIS FILE
---------------------
 * Introduction
 * Installation

INTRODUCTION
------------

It does the following:

    * Autodetects entity types and boolean bundle properties
    * Provides an extra Views Field for each Bundle/Property combination
    * Provides a new Field Type for Boolean fields
    * Provides a Field Widget for iToggle Fields
    * Provides a Field Formatter for both iToggle and Boolean Fields
    * Allows iToggle widget to be used for editing node properties: status, promote & sticky

iToggle does not yet do the following

    * Allow generic entity properties to be toggled in entity edit forms

The iToggle widgets can optionally trigger AJAX requests that toggle entity properties or field values.
Permissions are checked and a security token is validated before executing the action to avoid exploits.


INSTALLATION
------------

 * Extract the module in your sites/all/modules or sites/all/modules/contrib directory and enable it
