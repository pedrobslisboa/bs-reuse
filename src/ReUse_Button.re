type variant = [ | `default | `text | `outline];
type styles = {
  root: string,
  variant: string,
};


[@react.component]
let make =
    (
      ~onClick=?,
      ~type_="button",
      ~children=?,
      ~disabled=false,
      ~variant=`default,
    ) => {
  let defaultStyles: ReUse_Button_Styles.return =
    ReUse_Button_Styles.styles(
      React.useContext(ReUse_Theme_Context.context),
  );

  <button className={Cn.make([defaultStyles.root, defaultStyles.variant(variant)])} type_ disabled ?onClick>
    {Helpers.optionalChildren(children)}
  </button>;
};