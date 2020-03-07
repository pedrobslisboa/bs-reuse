open Css;

let root =
  style([
    display(flexBox),
    fontWeight(`num(600)),
    alignItems(center),
    justifyContent(center),
    boxShadow(StyleVars.shadow.button),
    borderStyle(none),
    padding2(~v=px(8), ~h=px(16)),
    cursor(`pointer),
    borderRadius(StyleVars.borderRadius),
    fontFamily(`custom("'Montserrat', sans-serif;")),
    letterSpacing(em(0.02)),
    lineHeight(`abs(1.75)),
    outlineStyle(none),
    selector(
        "&:disabled",
        [
          color(StyleVars.colors.disabled)
        ],
      ),
  ]);

let variant = (variant) => {
  switch variant {
  | `default => 
    style([
      backgroundColor(rgb(213,213,213)),
    ])
  | `text =>
    style([
      backgroundColor(transparent),
      boxShadow(none),
    ]);
  | `outline =>
    style([
      backgroundColor(transparent),
      boxShadow(none),
      borderWidth(px(1)),
      borderStyle(solid),
      borderColor(StyleVars.colors.default)
    ]);
  };
};

let color = (variant, colorVariant) => {
  let defaultVariant =
   switch variant {
        | `default => 
          style([])
        | `text => 
          style([
            color(StyleVars.colors.default)
          ])
        | `outline => 
          style([
            color(StyleVars.colors.default)
          ])
        };
  let primaryVariant =
   switch variant {
        | `default => 
          style([
            color(StyleVars.colors.default)
          ])
        | `text => 
          style([
            color(StyleVars.colors.primary)
          ])
        | `outline => 
          style([
            backgroundColor(rgb(213,213,213))
          ])
        };
  let secondaryVariant =
   switch variant {
        | `default => 
          style([
            backgroundColor(rgb(213,213,213))
          ])
        | `text => 
          style([
            backgroundColor(rgb(213,213,213))
          ])
        | `outline => 
          style([
            backgroundColor(rgb(213,213,213))
          ])
        };

  switch colorVariant {
    | `primary => primaryVariant
    | `secondary => secondaryVariant
    | `default => defaultVariant
  };
}