import React from "react";

function TodoItem(props) {
  let [isClicked, setIsClicked] = React.useState(false);

  function reverseState(e) {
    //setIsClicked(!isClicked);
    props.deleteItem(props.id);
  }

  return (
    <li
      style={{ textDecoration: isClicked == true ? "line-through" : null }}
      onClick={reverseState}
    >
      {props.name}
    </li>
  );
}

export default TodoItem;
