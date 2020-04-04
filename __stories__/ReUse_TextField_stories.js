'use strict';

var Css = require("bs-css-emotion/src/Css.js");
var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var ReUse_TextField = require("../src/ReUse_TextField.js");
var React$1 = require("@storybook/react");

var inputsWrapper = Curry._1(Css.style, /* :: */[
      Css.display(/* flex */-1010954439),
      /* :: */[
        Css.marginBottom(Css.px(40)),
        /* :: */[
          Css.marginTop(Css.px(10)),
          /* [] */0
        ]
      ]
    ]);

var textField = Curry._1(Css.style, /* :: */[
      Css.padding2(Css.px(0), Css.px(10)),
      /* [] */0
    ]);

var Styles = {
  inputsWrapper: inputsWrapper,
  textField: textField
};

var _module = module;

React$1.storiesOf("Elements | Text Field", _module).add("default", (function (param) {
          return React.createElement("div", undefined, React.createElement("strong", undefined, "Labeled"), React.createElement("div", {
                          className: inputsWrapper
                        }, React.createElement(ReUse_TextField.make, {
                              placeholder: "Default",
                              label: "Default",
                              className: textField
                            }), React.createElement(ReUse_TextField.make, {
                              placeholder: "Default invalid",
                              label: "Default Invalid",
                              className: textField,
                              valid: false
                            }), React.createElement(ReUse_TextField.make, {
                              placeholder: "Outline invalid",
                              variant: /* outlined */613841570,
                              label: "Outlined",
                              className: textField
                            }), React.createElement(ReUse_TextField.make, {
                              placeholder: "Outline invalid",
                              variant: /* outlined */613841570,
                              label: "Error",
                              className: textField,
                              valid: false
                            })), React.createElement("strong", undefined, "Without label"), React.createElement("div", {
                          className: inputsWrapper
                        }, React.createElement(ReUse_TextField.make, {
                              placeholder: "Without label",
                              className: textField
                            }), React.createElement(ReUse_TextField.make, {
                              placeholder: "Without label invalid",
                              className: textField,
                              valid: false
                            }), React.createElement(ReUse_TextField.make, {
                              placeholder: "Without label outline",
                              variant: /* outlined */613841570,
                              className: textField
                            }), React.createElement(ReUse_TextField.make, {
                              placeholder: "Without label outline invalid",
                              variant: /* outlined */613841570,
                              className: textField,
                              valid: false
                            })));
        })).add("filled", (function (param) {
        return React.createElement("div", undefined, React.createElement("strong", undefined, "Labeled"), React.createElement("div", {
                        className: inputsWrapper
                      }, React.createElement(ReUse_TextField.make, {
                            placeholder: "Filled",
                            label: "Filled",
                            className: textField,
                            filled: true
                          }), React.createElement(ReUse_TextField.make, {
                            placeholder: "Filled invalid",
                            label: "Filled Invalid",
                            className: textField,
                            valid: false,
                            filled: true
                          }), React.createElement(ReUse_TextField.make, {
                            placeholder: "Filled Outline",
                            variant: /* outlined */613841570,
                            label: "Filled Outline",
                            className: textField,
                            filled: true
                          }), React.createElement(ReUse_TextField.make, {
                            placeholder: "Filled Outline invalid",
                            variant: /* outlined */613841570,
                            label: "Filled Outline invalid",
                            className: textField,
                            valid: false,
                            filled: true
                          })), React.createElement("strong", undefined, "Without label"), React.createElement("div", {
                        className: inputsWrapper
                      }, React.createElement(ReUse_TextField.make, {
                            placeholder: "Filled",
                            className: textField,
                            filled: true
                          }), React.createElement(ReUse_TextField.make, {
                            placeholder: "Filled invalid",
                            className: textField,
                            valid: false,
                            filled: true
                          }), React.createElement(ReUse_TextField.make, {
                            placeholder: "Filled Outline",
                            variant: /* outlined */613841570,
                            className: textField,
                            filled: true
                          }), React.createElement(ReUse_TextField.make, {
                            placeholder: "Filled Outline invalid",
                            variant: /* outlined */613841570,
                            className: textField,
                            valid: false,
                            filled: true
                          })));
      }));

exports.Styles = Styles;
exports._module = _module;
/* inputsWrapper Not a pure module */
