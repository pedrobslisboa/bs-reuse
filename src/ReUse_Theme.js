'use strict';

var Css = require("bs-css-emotion/src/Css.js");
var Curry = require("bs-platform/lib/js/curry.js");
var Lodash = require("lodash");
var Css_Core = require("bs-css/src/Css_Core.js");

var shape = {
  borderRadius: Css.px(4)
};

var colors = {
  disabled: Css.rgb(128, 128, 128),
  default: Css.hex("000000")
};

var shadow = {
  elevation: [
    Css_Core.Shadow.box(undefined, Css.px(3), Css.px(5), undefined, undefined, Css.rgba(0, 0, 0, 0.3)),
    Css_Core.Shadow.box(undefined, Css.px(5), Css.px(8), undefined, undefined, Css.rgba(0, 0, 0, 0.3))
  ]
};

var theme = {
  colors: colors,
  shadow: shadow,
  shape: shape
};

function changeTheme(cb) {
  var dictTheme = theme;
  return Curry._1(cb, Lodash.cloneDeep(dictTheme));
}

exports.shape = shape;
exports.colors = colors;
exports.shadow = shadow;
exports.theme = theme;
exports.changeTheme = changeTheme;
/* shape Not a pure module */
