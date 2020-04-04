module Styles = {
  open Css;

  type theme = ReUse_Theme.t;
  type styles = {
    wrapper: string,
    input: string,
    label: string,
    shrink: string,
    expand: string,
    labelWrapper: string,
    variantOutlined: string,
    variantDefault: string,
    labeled: string,
    filled: string,
    invalid: string,
  };

  let styles = (theme: theme) => {
    let transition = delay => transition(~duration=100, ~delay, ~timingFunction=easeOut, "all");

    let expand = style([label("expand")]);

    let variantOutlined = style([label("variantOutlined")]);

    let variantDefault = style([label("variantDefault")]);

    let filled = style([label("filled")]);

    let labeled = style([marginTop(px(20)), label("labeled")]);

    let invalid = style([label("invalid")]);

    let labelWrapper =
      style([
        fontFamily(theme.fontFamily),
        transition(0),
        position(absolute),
        width(`percent(100.0)),
        height(`percent(100.0)),
        bottom(zero),
        left(zero),
        selector(
          "&::after",
          [
            zIndex(-1),
            transition(0),
            contentRule(`text("")),
            width(`percent(100.00)),
            position(absolute),
            bottom(zero),
            left(zero),
            backgroundColor(rgb(213, 213, 213)),
            borderRadius(px(4)),
            boxSizing(borderBox),
            height(`percent(100.0)),
            selector({j|.$variantDefault &|j}, [backgroundColor(rgb(213, 213, 213))]),
            selector(
              {j|.$variantOutlined &|j},
              [
                borderStyle(solid),
                borderWidth(px(1)),
                borderColor(rgb(0, 0, 0)),
                backgroundColor(rgb(255, 255, 255)),
              ],
            ),
            selector({j|.$default.$variantOutlined &|j}, [height(px(0))]),
            selector({j|.$default.$variantDefault &|j}, [height(px(2))]),
            selector({j|.$default.$expand &, .$filled &|j}, [height(`percent(100.00))]),
            selector({j|.$invalid &|j}, [borderStyle(solid), borderWidth(px(1)), borderColor(hex("f44336"))]),
          ],
        ),
      ]);

    let label =
      style([
        fontSize(px(16)),
        letterSpacing(em(0.02)),
        padding(px(2)),
        transition(0),
        position(absolute),
        bottom(px(2)),
        left(zero),
        selector({j|.$expand &, .$filled &|j}, [fontSize(px(12)), bottom(`percent(100.0))]),
        selector({j|.$invalid &|j}, [color(hex("f44336"))]),
      ]);

    let shrink = style([display(block)]);

    let wrapper =
      style([
        display(block),
        boxSizing(borderBox),
        position(relative),
        height(px(40)),
        width(`percent(100.0)),
        zIndex(0),
      ]);

    let input =
      style([
        boxSizing(borderBox),
        color(transparent),
        transition(0),
        padding2(~v=zero, ~h=px(15)),
        lineHeight(`percent(100.0)),
        position(relative),
        backgroundColor(transparent),
        zIndex(1),
        width(`percent(100.00)),
        height(`percent(100.00)),
        borderStyle(`none),
        outlineStyle(none),
        selector({j|&::placeholder|j}, [transition(0), color(transparent)]),
        selector(
          {j|.$expand &, &:not(:placeholder-shown)|j},
          [color(black), transition(70), selector({j|&::placeholder|j}, [transition(70), color(grey)])],
        ),
        selector({j|.$filled &::placeholder|j}, [color(grey)]),
        selector({j|&:not(:placeholder-shown) ~ .$labelWrapper:after|j}, [height(`percent(100.0))]),
        selector(
          {j|&:not(:placeholder-shown) ~ .$labelWrapper .$label|j},
          [bottom(`percent(100.0)), fontSize(px(12))],
        ),
      ]);

    {wrapper, input, label, shrink, labelWrapper, expand, variantOutlined, variantDefault, labeled, invalid, filled};
  };
};

type label = {
  labeled: bool,
  label: string,
};

[@react.component]
let make =
    (~value=?, ~placeholder=" ", ~onChange=?, ~variant=`default, ~label=?, ~className="", ~valid=true, ~filled=false) => {
  let theme = React.useContext(ReUse_Theme_Context.context);
  let (focus, setFocus) = React.useState(() => false);
  let defaultStyles: Styles.styles = Styles.styles(theme);

  let variantStyle =
    switch (variant) {
    | `outlined => defaultStyles.variantOutlined
    | `default => defaultStyles.variantDefault
    };

  let renderLabel =
    switch (label) {
    | Some(label) => <span className={Cn.make([defaultStyles.label])}> label->React.string </span>
    | None => ""->React.string
    };

  let labelStyle =
    switch (label) {
    | Some(label) => defaultStyles.labeled
    | None => ""
    };

  <div className>
    <label
      className={
        Cn.make([
          defaultStyles.expand->Cn.ifTrue(focus),
          labelStyle,
          defaultStyles.invalid->Cn.ifTrue(!valid),
          defaultStyles.filled->Cn.ifTrue(filled),
          defaultStyles.wrapper,
          variantStyle,
        ])
      }>
      <input
        ?onChange
        ?value
        placeholder
        onFocus={_ => setFocus(_ => true)}
        onBlur={_ => setFocus(_ => false)}
        className={Cn.make([defaultStyles.input])}
      />
      <span className={Cn.make([defaultStyles.labelWrapper])}> renderLabel </span>
    </label>
  </div>;
};
