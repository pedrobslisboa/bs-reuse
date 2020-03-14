'use strict';

var Caml_option = require("bs-platform/lib/js/caml_option.js");

function optionalChildren(children) {
  if (children !== undefined) {
    return Caml_option.valFromOption(children);
  } else {
    return "";
  }
}

exports.optionalChildren = optionalChildren;
/* No side effect */
