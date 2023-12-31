import React from "react";

function InputArea(props) {
  let [inputText, setInputText] = React.useState("");

  function handleChange(event) {
    setInputText(event.target.value);
  }

  function addItem(event) {
    props.addItem(inputText);
    setInputText("");
  }

  return (
    <div className="form">
      <input onChange={handleChange} type="text" value={inputText} />
      <button onClick={addItem}>
        <span>Add</span>
      </button>
    </div>
  );
}

export default InputArea;
