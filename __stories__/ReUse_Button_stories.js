'use strict';

var Css = require("bs-css-emotion/src/Css.js");
var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var ReUse_Button = require("../src/ReUse_Button.js");
var React$1 = require("@storybook/react");

var buttonsWrapper = Curry._1(Css.style, /* :: */[
      Css.display(/* flex */-1010954439),
      /* :: */[
        Css.marginBottom(Css.px(40)),
        /* :: */[
          Css.marginTop(Css.px(10)),
          /* [] */0
        ]
      ]
    ]);

var button = Curry._1(Css.style, /* :: */[
      Css.marginRight(Css.px(20)),
      /* [] */0
    ]);

var Styles = {
  buttonsWrapper: buttonsWrapper,
  button: button
};

var _module = module;

React$1.storiesOf("Elements | Button", _module).add("default", (function (param) {
              return React.createElement("div", {
                          className: buttonsWrapper
                        }, React.createElement(ReUse_Button.make, {
                              className: button,
                              children: "DEFAULT"
                            }), React.createElement(ReUse_Button.make, {
                              className: button,
                              children: "ELEVATED",
                              elevated: true
                            }));
            })).add("disabled", (function (param) {
            return React.createElement("div", {
                        className: buttonsWrapper
                      }, React.createElement(ReUse_Button.make, {
                            className: button,
                            children: "DISABLE",
                            disabled: true
                          }), React.createElement(ReUse_Button.make, {
                            className: button,
                            children: "ELEVATED",
                            disabled: true,
                            elevated: true
                          }));
          })).add("Text button", (function (param) {
          return React.createElement("div", undefined, React.createElement(ReUse_Button.make, {
                          children: "TEXT",
                          variant: /* text */-856044371
                        }));
        })).add("Outlined", (function (param) {
        return React.createElement("div", undefined, React.createElement(ReUse_Button.make, {
                        children: "OUTLINED",
                        variant: /* outlined */613841570
                      }));
      }));

exports.Styles = Styles;
exports._module = _module;
/* buttonsWrapper Not a pure module */
