type t;
open CounterReducer;

[@bs.module "redux-devtools-extension"] external composeWithDevTools: t => t = "";

[@bs.module "redux"] external combineReducers: reducer => t = "";

[@bs.module "redux"] external createStore: (t, t) => t = "";

[@bs.module "react-redux"] external connect: (t, t) => t = "";

[@bs.module "react-redux"] external applyMiddleware: unit => t = "";

module Provider = {
  [@bs.module "react-redux"][@react.component]
  external make: (~store: t, ~children: React.element=?) => React.element = "Provider";
}
