open Redux;
open RxJs.Redux;
open CounterReducer;

let store = 
createStore(combineReducers({"counter": counter}), composeWithDevTools(applyMiddleware()));
