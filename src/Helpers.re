let optionalChildren = children =>
  switch (children) {
  | Some(children) => children
  | None => React.string("")
  };

module Children = {
  [@bs.module "react"] [@bs.scope "Children"] [@bs.val]
  external map: (React.element, Js.Dict.t('a) => React.element) => React.element = "map";
  [@bs.module "react"] [@bs.scope "Children"] [@bs.val]
  external forEach: (React.element, Js.Dict.t('a) => unit) => unit = "forEach";
  [@bs.module "react"] [@bs.scope "Children"] [@bs.val] external count: React.element => int = "count";
  [@bs.module "react"] [@bs.scope "Children"] [@bs.val] external only: React.element => React.element = "only";
  [@bs.module "react"] [@bs.scope "Children"] [@bs.val]
  external toArray: React.element => array(React.element) = "toArray";
};
