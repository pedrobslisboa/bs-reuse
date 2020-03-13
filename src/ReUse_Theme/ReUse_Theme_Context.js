'use strict';

var React = require("react");
var ReUse_Theme$BsReuse = require("./ReUse_Theme.js");

var context = React.createContext(ReUse_Theme$BsReuse.theme);

function makeProps(value, children, param) {
  return {
          value: value,
          children: children
        };
}

var make = context.Provider;

var Provider = {
  makeProps: makeProps,
  make: make
};

exports.context = context;
exports.Provider = Provider;
/* context Not a pure module */
