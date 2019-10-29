external toT : 'a => Redux.t = "%identity";
open Redux;

let str = ReasonReact.string;
let noop = () => ();
open CounterActions;

[@react.component]
let make = (~counter=0, ~incrementCounter=noop, ~decrementCounter=noop) => {
  <div>
    <h1>"ReasonReact POC" -> str</h1>
    <p>counter -> string_of_int -> str</p>
    <button onClick=(_e => incrementCounter())>"Increment" -> str</button>
    <button onClick=(_e => decrementCounter())>"Decrement" -> str</button>
    </div>
};

let mapDispatchToProps = dispatch => {
  {
    "incrementCounter": () => dispatch({"type": "counter/increment", "tag": Increment}),
    "decrementCounter": () => dispatch({"type": "counter/decrement", "tag": Decrement})
  }
}


let mapStateToProps = state => {
  "counter": state##counter##counter,
};

let connect = connect(mapStateToProps |> toT, mapDispatchToProps |> toT);

[%raw "App = connect(App)"];
