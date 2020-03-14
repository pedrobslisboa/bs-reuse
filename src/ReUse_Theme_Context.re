let context = React.createContext(ReUse_Theme.theme);

module Provider = {
  let makeProps = (~value, ~children, ()) => {"value": value, "children": children};

  let make = React.Context.provider(context);
};
