open CounterActions;

[@bs.deriving {abstract: light}]
type state_ = {
  counter: int,
};

type reducer = {
  .
  "counter": (state_, action) => state_ 
};
let initialState = state_(~counter=0);

let resolveOption = option => {
  switch(option) {
  | None => initialState
  | Some(state) => state
  }
};


let counter = (state, action) =>
  if(state == [%raw "undefined"]) {
    initialState
  } else {
  switch(action -> tag) {
  | Increment => state_(~counter=state -> counter + 1)
  | Decrement => state_(~counter=state -> counter - 1)
  | _ => state
  }
  } 
