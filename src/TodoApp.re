type item = {
  title: string,
  completed: bool,
};

let valueFromEvent = (evt): string =>
  (evt |> ReactEventRe.Form.target |> ReactDOMRe.domElementToObj)##value;

module Input = {
  type state = string;
  let component = ReasonReact.reducerComponent("Input");
  let make = (~onSubmit, _) => {
    ...component,
    initialState: () => "",
    reducer: (newText, _text) => ReasonReact.Update(newText),
    render: ({state: text, send}) =>
      <input
        value=text
        type_="text"
        placeholder="Write something to do"
        onChange={evt => send(valueFromEvent(evt))}
        onKeyDown={evt =>
          if (ReactEvent.Keyboard.key(evt) == "Enter") {
            onSubmit(text);
            send("");
          }
        }
      />,
  };
};

module Item = {
  let component = ReasonReact.statelessComponent("Item");
  let make = (~item, ~onToggle, children) => {
    ...component,
    render: self => {
      <div className="item">
        <input
          type_="checkbox"
          checked={item.completed}
          onChange={_ => onToggle(item)}
        />
        {ReasonReact.string(item.title)}
      </div>;
    },
  };
};

module AddButton = {
  let component = ReasonReact.statelessComponent("AddButton");
};

type action =
  | Toggle(item)
  | Add(string)
  | Remove(item);

type state = {items: list(item)};

let component = ReasonReact.reducerComponent("TodoApp");

let make = children => {
  ...component,

  initialState: () => {items: []},

  reducer: (action, state) =>
    switch (action) {
    | Add(title) =>
      ReasonReact.Update({
        ...state,
        items: [{title, completed: false}, ...state.items],
      })
    | Remove(todo) =>
      ReasonReact.Update({
        ...state,
        items: List.filter(t => t != todo, state.items),
      })
    | Toggle(todo) =>
      ReasonReact.Update({
        ...state,
        items:
          List.map(
            i => i != todo ? i : {...todo, completed: !todo.completed},
            state.items,
          ),
      })
    },

  render: ({state: {items}, send}) =>
    <div className="app">
      <h1> {ReasonReact.string("What to do?")} </h1>
      <Input onSubmit={text => send(Add(text))} />
      <section>
        {ReasonReact.array(
           Array.of_list(
             List.map(
               item => <Item onToggle={_ => send(Toggle(item))} item />,
               items,
             ),
           ),
         )}
      </section>
    </div>,
};