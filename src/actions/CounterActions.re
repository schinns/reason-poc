type actions = 
| Increment
| Decrement
| Reset;

[@bs.deriving {abstract: light}]
type action = {
  [@bs.as "type"] type_: string,
  tag: actions,
};

let incrementCounter = () => action(~type_="counter/increment", ~tag=Increment);

let decrementCounter = () => action(~type_="counter/decrement", ~tag=Decrement);
