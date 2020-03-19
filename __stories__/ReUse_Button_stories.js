'use strict';

var Css = require("bs-css-emotion/src/Css.js");
var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var ReUse_Button = require("../src/ReUse_Button.js");
var React$1 = require("@storybook/react");

var _module = module;

var root = Curry._1(Css.style, /* :: */[
      Css.display(Css.flexBox),
      /* :: */[
        Css.fontWeight(/* `num */[
              5496390,
              600
            ]),
        /* :: */[
          Css.alignItems(Css.center),
          /* :: */[
            Css.justifyContent(Css.center),
            /* :: */[
              Css.borderStyle(Css.none),
              /* :: */[
                Css.padding2(Css.px(8), Css.px(16)),
                /* :: */[
                  Css.cursor(/* pointer */-786317123),
                  /* :: */[
                    Css.borderRadius(Css.px(50)),
                    /* :: */[
                      Css.fontFamily(/* `custom */[
                            1066567601,
                            "'Montserrat', sans-serif;"
                          ]),
                      /* :: */[
                        Css.letterSpacing(Css.em(0.02)),
                        /* :: */[
                          Css.lineHeight(/* `abs */[
                                4845682,
                                1.75
                              ]),
                          /* :: */[
                            Css.outlineStyle(Css.none),
                            /* [] */0
                          ]
                        ]
                      ]
                    ]
                  ]
                ]
              ]
            ]
          ]
        ]
      ]
    ]);

React$1.storiesOf("Elements | Button", _module).add("default", (function (param) {
              return React.createElement(ReUse_Button.make, {
                          children: "DEFAULT"
                        });
            })).add("disabled", (function (param) {
            return React.createElement(ReUse_Button.make, {
                        children: "DISABLE",
                        disabled: true
                      });
          })).add("Text button", (function (param) {
          return React.createElement("div", undefined, React.createElement(ReUse_Button.make, {
                          children: "TEXT",
                          variant: /* text */-856044371
                        }));
        })).add("Outlined", (function (param) {
        return React.createElement("div", undefined, React.createElement(ReUse_Button.make, {
                        children: "OUTLINED",
                        variant: /* outline */-507635838
                      }));
      }));

exports._module = _module;
exports.root = root;
/* _module Not a pure module */
