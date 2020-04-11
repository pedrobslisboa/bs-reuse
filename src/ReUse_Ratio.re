type variant = [ | `default | `text | `outline];

module Styles = {
  open Css;

  type styles = {
    root: string,
    input: string,
    ratio: string,
    checked: string,
  };

  type theme = ReUse_Theme.t;

  let styles = (theme: theme) => {
    let transition = delay => transition(~duration=100, ~delay, ~timingFunction=easeOut, "all");

    let root = style([display(flexBox), position(relative), letterSpacing(em(0.00938))]);

    let checked = style([label("checked")]);

    let ratio =
      style([
        backgroundColor(rgb(213, 213, 213)),
        display(block),
        position(relative),
        top(zero),
        left(zero),
        height(em(1.0)),
        width(em(1.0)),
        cursor(pointer),
        marginRight(px(8)),
        borderRadius(`percent(50.0)),
        selector(
          {j|&:after|j},
          [
            contentRule(`text("")),
            position(absolute),
            margin(auto),
            borderRadius(`percent(50.0)),
            transform(scale(0.0, 0.0)),
            transition(0),
            width(em(0.6)),
            height(em(0.6)),
            top(zero),
            bottom(zero),
            left(zero),
            right(zero),
            backgroundColor(hex("1890ff")),
          ],
        ),
        selector({j|.$checked &:after|j}, [transform(scale(1.0, 1.0))]),
      ]);

    let input =
      style([
        position(absolute),
        top(zero),
        bottom(zero),
        left(zero),
        right(zero),
        zIndex(1),
        cursor(pointer),
        opacity(0.0),
      ]);

    {root, input, ratio, checked};
  };
};

[@react.component]
let make = (~value, ~className="", ~label, ~onClick=?, ~disabled=false, ~checked=false) => {
  let defaultStyles: Styles.styles = Styles.styles(React.useContext(ReUse_Theme_Context.context));

  let handleClick = _ =>
    switch (onClick) {
    | Some(fn) => fn()
    | None => ()
    };

  <label className={Cn.make([defaultStyles.root, defaultStyles.checked->Cn.ifTrue(checked), className])}>
    <span>
      <input className={Cn.make([defaultStyles.input])} type_="radio" disabled onClick=handleClick value />
      <span className={defaultStyles.ratio} />
    </span>
    <span> label->React.string </span>
  </label>;
};
