'use strict';

var Cn = require("re-classnames/src/Cn.bs.js");
var Css = require("bs-css-emotion/src/Css.js");
var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var Helpers = require("./Helpers.js");
var Caml_array = require("bs-platform/lib/js/caml_array.js");
var Caml_option = require("bs-platform/lib/js/caml_option.js");
var ReUse_Theme_Context = require("./ReUse_Theme_Context.js");

function styles(theme) {
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
                Css.boxShadow(Caml_array.caml_array_get(theme.shadow.elevation, 0)),
                /* :: */[
                  Css.borderStyle(Css.none),
                  /* :: */[
                    Css.padding2(Css.px(8), Css.px(16)),
                    /* :: */[
                      Css.cursor(/* pointer */-786317123),
                      /* :: */[
                        Css.borderRadius(theme.shape.borderRadius),
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
                                /* :: */[
                                  Css.selector("&:disabled", /* :: */[
                                        Css.color(theme.colors.disabled),
                                        /* [] */0
                                      ]),
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
          ]
        ]
      ]);
  var variant = function (variant$1) {
    if (variant$1 !== -507635838) {
      if (variant$1 >= 465819841) {
        return Curry._1(Css.style, /* :: */[
                    Css.backgroundColor(Css.rgb(213, 213, 213)),
                    /* [] */0
                  ]);
      } else {
        return Curry._1(Css.style, /* :: */[
                    Css.backgroundColor(Css.transparent),
                    /* :: */[
                      Css.boxShadow(Css.none),
                      /* [] */0
                    ]
                  ]);
      }
    } else {
      return Curry._1(Css.style, /* :: */[
                  Css.backgroundColor(Css.transparent),
                  /* :: */[
                    Css.boxShadow(Css.none),
                    /* :: */[
                      Css.borderWidth(Css.px(1)),
                      /* :: */[
                        Css.borderStyle(Css.solid),
                        /* :: */[
                          Css.borderColor(theme.colors.default),
                          /* [] */0
                        ]
                      ]
                    ]
                  ]
                ]);
    }
  };
  return {
          root: root,
          variant: variant
        };
}

var Styles = {
  styles: styles
};

function ReUse_Button(Props) {
  var onClick = Props.onClick;
  var $staropt$star = Props.type_;
  var children = Props.children;
  var $staropt$star$1 = Props.disabled;
  var $staropt$star$2 = Props.variant;
  var type_ = $staropt$star !== undefined ? $staropt$star : "button";
  var disabled = $staropt$star$1 !== undefined ? $staropt$star$1 : false;
  var variant = $staropt$star$2 !== undefined ? $staropt$star$2 : /* default */465819841;
  var defaultStyles = styles(React.useContext(ReUse_Theme_Context.context));
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

exports.Styles = Styles;
exports.make = make;
/* Css Not a pure module */
