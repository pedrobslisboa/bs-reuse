'use strict';

var Css = require("bs-css-emotion/src/Css.js");
var Curry = require("bs-platform/lib/js/curry.js");
var Caml_array = require("bs-platform/lib/js/caml_array.js");

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

exports.styles = styles;
/* Css Not a pure module */
