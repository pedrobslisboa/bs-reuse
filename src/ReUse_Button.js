'use strict';

var Cn = require("re-classnames/src/Cn.bs.js");
var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var Helpers = require("./Helpers.js");
var Caml_option = require("bs-platform/lib/js/caml_option.js");
var ReUse_Button_Styles = require("./ReUse_Button_Styles.js");
var ReUse_Theme_Context = require("./ReUse_Theme_Context.js");

function ReUse_Button(Props) {
  var onClick = Props.onClick;
  var $staropt$star = Props.type_;
  var children = Props.children;
  var $staropt$star$1 = Props.disabled;
  var $staropt$star$2 = Props.variant;
  var type_ = $staropt$star !== undefined ? $staropt$star : "button";
  var disabled = $staropt$star$1 !== undefined ? $staropt$star$1 : false;
  var variant = $staropt$star$2 !== undefined ? $staropt$star$2 : /* default */465819841;
  var defaultStyles = ReUse_Button_Styles.styles(React.useContext(ReUse_Theme_Context.context));
  var tmp = {
    className: Cn.make(/* :: */[
          defaultStyles.root,
          /* :: */[
            Curry._1(defaultStyles.variant, variant),
            /* [] */0
          ]
        ]),
    disabled: disabled,
    type: type_
  };
  if (onClick !== undefined) {
    tmp.onClick = Caml_option.valFromOption(onClick);
  }
  return React.createElement("button", tmp, Helpers.optionalChildren(children));
}

var make = ReUse_Button;

exports.make = make;
/* react Not a pure module */
