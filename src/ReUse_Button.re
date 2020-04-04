type variant = [ | `default | `text | `outline];

module Styles = {
  open Css;

  type styles = {
    root: string,
    variantDefault: string,
    variantText: string,
    variantOutlined: string,
    elevated: string,
  };

  type theme = ReUse_Theme.t;

  let styles = (theme: theme) => {
    let elevated = style([boxShadow(theme.shadow.elevation[0])]);

    let root =
      style([
        display(flexBox),
        fontWeight(`num(600)),
        alignItems(center),
        justifyContent(center),
        borderStyle(none),
        padding2(~v=px(8), ~h=px(16)),
        cursor(`pointer),
        borderRadius(theme.shape.borderRadius),
        fontFamily(`custom("'Montserrat', sans-serif;")),
        letterSpacing(em(0.02)),
        lineHeight(`abs(1.75)),
        outlineStyle(none),
        selector("&:disabled", [cursor(notAllowed), color(theme.colors.disabled)]),
      ]);

    let variantOutlined =
      style([
        backgroundColor(transparent),
        boxShadow(none),
        borderWidth(px(1)),
        borderStyle(solid),
        borderColor(theme.colors.default),
      ]);

    let variantText = style([backgroundColor(transparent), boxShadow(none)]);

    let variantDefault = style([backgroundColor(rgb(213, 213, 213))]);

    {root, variantDefault, variantOutlined, variantText, elevated};
  };
};

[@react.component]
let make =
    (~className="", ~onClick=?, ~type_="button", ~children=?, ~disabled=false, ~variant=`default, ~elevated=false) => {
  let defaultStyles: Styles.styles = Styles.styles(React.useContext(ReUse_Theme_Context.context));

  let variantStyle =
    switch (variant) {
    | `outlined => defaultStyles.variantOutlined
    | `default => defaultStyles.variantDefault
    | `text => defaultStyles.variantText
    };

  <button
    className={Cn.make([defaultStyles.root, variantStyle, defaultStyles.elevated->Cn.ifTrue(elevated), className])}
    type_
    disabled
    ?onClick>
    {Helpers.optionalChildren(children)}
  </button>;
};
