import React from "react";

function CreateArea(props) {
  let [title, setTitle] = React.useState("");
  let [content, setContent] = React.useState("");

  function onTitleChange(event) {
    setTitle(event.target.value);
  }

  function onContentChange(event) {
    setContent(event.target.value);
  }

  function storeNote() {
    if (title || content) {
      props.onAddNote(title, content);
    }
    setTitle("");
    setContent("");
  }

  function submitForm(event) {
    event.preventDefault();
  }

  return (
    <div>
      <form onSubmit={submitForm}>
        <input
          name="title"
          onChange={onTitleChange}
          placeholder="Title"
          maxlength="25"
          value={title}
        />
        <textarea
          name="content"
          onChange={onContentChange}
          placeholder="Take a note..."
          rows="4"
          maxlength="500"
          value={content}
        />
        <button onClick={storeNote}>Add</button>
      </form>
    </div>
  );
}

export default CreateArea;
