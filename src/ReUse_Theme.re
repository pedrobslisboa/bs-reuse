open Css;
[@bs.module "lodash"] external cloneDeep: Js.Dict.t(_) => _ = "cloneDeep";

type colors = {
  mutable disabled: Css_AtomicTypes.Color.t,
  mutable default: Css_AtomicTypes.Color.t,
};

type shape = {
  mutable borderRadius: Css_AtomicTypes.Length.t
};

type elevation = array(Shadow.t(Shadow.box));

type shadow = { mutable elevation };

type t = {
  colors,
  shadow,
  shape,
};

let shape = {
  borderRadius: px(4)
}

let colors = {
  default: hex("000000"),
  disabled: rgb(128, 128, 128),
};

let shadow = {
  elevation: [|
    Shadow.box(~y=px(3), ~blur=px(5), rgba(0, 0, 0, 0.3)),
    Shadow.box(~y=px(5), ~blur=px(8), rgba(0, 0, 0, 0.3)),
  |]
};

let theme = {
  {shape, colors, shadow};
};

let changeTheme = (cb) => {
  let dictTheme =[%bs.raw {| theme |}];
  let themeClone: t = cloneDeep(dictTheme);
  
  let newTheme = cb(themeClone);

  newTheme;
} 
