open Css;
type variant = [ | `default | `text | `outline];

type return = {
  root: string,
  variant: variant => string
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

  let variant: (variant) => string = variant => {
    switch (variant) {
    | `default => style([backgroundColor(rgb(213, 213, 213))])
    | `text => style([backgroundColor(transparent), boxShadow(none)])
    | `outline =>
      style([
        backgroundColor(transparent),
        boxShadow(none),
        borderWidth(px(1)),
        borderStyle(solid),
        borderColor(theme.colors.default),
      ])
    };
  };

  {root, variant};
};