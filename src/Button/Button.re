type variant = [ | `default | `text | `outline];

[@react.component]
let make =
    (
      ~onClick=?,
      ~type_="button",
      ~children=?,
      ~disabled=false,
      ~variant=`default
    ) => {

  <button
    className={Cn.make([
      Button_Styles.root,
      Button_Styles.variant(variant),
      Button_Styles.color(variant, color),
    ])}
    type_
    disabled
    onClick={evt => {
      switch (onClick) {
        | Some(onClick) => onClick()
        | None => ()
      };
    }}>
    {Helpers.optionalChildren(children)}
  </button>;
};