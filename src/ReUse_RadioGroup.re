open Helpers;

type radioProps = {
  label: string,
  value: string,
  checked: bool,
  className: string,
};
type child = {props: radioProps};

[@bs.module "lodash"] external cloneDeep: Js.Dict.t(_) => _ = "cloneDeep";

[@react.component]
let make = (~children, ~value="", ~onChange=?) => {
  let (currentValue, setCurrentValue) = React.useState(() => value);
  let mached = ref(false);
  let renderGroup = () =>
    Children.map(
      children,
      child => {
        let {label, value: childValue, checked: childChecked, className: childClassName} = cloneDeep(child).props;
        let checked = ref(childChecked);

        let handleClick = _ => {
          setCurrentValue(_ => childValue);
          mached := true;
        };

        if (currentValue === childValue) {
          checked := true;
        } else {
          checked := false;
        };

        <ReUse_Radio value=childValue checked=checked^ label onClick=handleClick className=childClassName />;
      },
    );

  switch (onChange) {
  | Some(fn) => fn(currentValue)
  | None => ()
  };

  <div> {renderGroup()} </div>;
};
