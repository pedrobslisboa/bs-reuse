type variant = [ | `default | `text | `outline];

module Styles = {
  open Css;

  type styles = {
    root: string,
    variantDefault: string,
    variantText: string,
    variantOutline: string,
  };

  type theme = ReUse_Theme.t;

  let styles = (theme: theme) => {
    let root =
      style([
        display(flexBox),
        fontWeight(`num(600)),
        alignItems(center),
        justifyContent(center),
        boxShadow(theme.shadow.elevation[0]),
        borderStyle(none),
        padding2(~v=px(8), ~h=px(16)),
        cursor(`pointer),
        borderRadius(theme.shape.borderRadius),
        fontFamily(`custom("'Montserrat', sans-serif;")),
        letterSpacing(em(0.02)),
        lineHeight(`abs(1.75)),
        outlineStyle(none),
        selector("&:disabled", [color(theme.colors.disabled)]),
      ]);

    let variantOutline =
      style([
        backgroundColor(transparent),
        boxShadow(none),
        borderWidth(px(1)),
        borderStyle(solid),
        borderColor(theme.colors.default),
      ]);

    let variantText = style([backgroundColor(transparent), boxShadow(none)]);

    let variantDefault = style([backgroundColor(rgb(213, 213, 213))]);

    {root, variantDefault, variantOutline, variantText};
  };
};

[@react.component]
let make = (~onClick=?, ~type_="button", ~children=?, ~disabled=false, ~variant=`default) => {
  let defaultStyles: Styles.styles = Styles.styles(React.useContext(ReUse_Theme_Context.context));

  let variantStyle =
    switch (variant) {
    | `outline => defaultStyles.variantOutline
    | `default => defaultStyles.variantDefault
    | `text => defaultStyles.variantText
    };

  <button className={Cn.make([defaultStyles.root, variantStyle])} type_ disabled ?onClick>
    {Helpers.optionalChildren(children)}
  </button>;
};
