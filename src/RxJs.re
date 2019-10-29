type t;
type observer('a);
type observable('a);
type fn('a) = 'a => 'a;
type fn2('a, 'b) = 'a => 'b;
type operatorFn('a, 'b) = fn2(observable('a), observable('b));

[@bs.send] external pipe : (t, fn('a)) => t = "pipe"
[@bs.send] external pipe2 : (t, fn('a), fn('b)) => t = "pipe"
[@bs.send] external pipe2_ : (t, fn2('a, 'b), fn2('b, 'c)) => observable('a) = "pipe"

module Ajax {
  [@bs.deriving {abstract: light}]
    type headers = {
      [@bs.as "Accept"] accept: string,
      [@bs.as "Content-Type"] contentType: string,
      [@bs.as "X-CSRF-Token"] xCsrfToken: string,
      [@bs.optional] url: string,
      [@bs.optional] [@bs.as "method"] method_: string,
    };

  [@bs.deriving {abstract: light}]
    type options = {
      url: string,
      [@bs.as "method"] methodx : string,
    };

  [@bs.module "rxjs/ajax"]
    external ajax : headers => t = "ajax";
};

module Operators {
  [@bs.module "rxjs/operators"]
    external map: ('a => 'b) => fn(observable(unit)) = "map";

  [@bs.module "rxjs/operators"]
    external pluck: ('a) => fn(observable(unit)) = "pluck";

  [@bs.module "rxjs/operators"]
    external flatMap : ('a => observable('b)) => fn('a) = "flatMap";

  [@bs.module "rxjs/operators"]
    external catchError: ('a => 'b) => fn(observable(unit)) = "catchError";
};

module Redux {
  [@bs.module "redux-observable"]
  external ofType : string => fn('a) = "ofType";

  type deps;
  type epics;
  [@bs.deriving {abstract: light}]
  type options = {
    dependencies: deps
  };
  [@bs.deriving {abstract: light}]
  type epicMiddleware = {
    run: epics => unit
  };

  [@bs.module "redux-observable"]
  external createEpicMiddleware : options => epicMiddleware = "createEpicMiddleware";
}

