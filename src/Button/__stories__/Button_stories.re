open BsStorybook.Story;
 
let _module = [%bs.raw "module"];
 
storiesOf("Elements | Button", _module)
|. add("default", () =>
     <Button> (ReasonReact.string("DEFAULT")) </Button>
   )
|. add("disabled", () => {
    let disabled = true;

     <Button disabled> (ReasonReact.string("DISABLE")) </Button>
   })
|. add("Text button", () => {
    <div>
     <Button variant=`text> (ReasonReact.string("TEXT")) </Button>
    </div>
   })
|. add("Outlined", () => {
    <div>
     <Button variant=`outline> (ReasonReact.string("OUTLINED")) </Button>
    </div>
   })