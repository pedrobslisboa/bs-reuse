open Css;
type colors ={
  mutable primary: Css_AtomicTypes.Color.t,
  mutable disabled: Css_AtomicTypes.Color.t,
  mutable default: Css_AtomicTypes.Color.t
};
type shadow = {
  mutable button: Shadow.t(Shadow.box) 
}

let borderRadius = px(4);

let colors:colors = {
  primary: hex("00a8cc"),
  default: hex("000000"),
  disabled: rgb(128,128,128),
}

let shadow = {
  button: Shadow.box(~y=px(3), ~blur=px(5), rgba(0, 0, 0, 0.3))
}