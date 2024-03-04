import React, { useState } from "react";
import AddIcon from "@mui/icons-material/Add";
import Fab from "@mui/material/Fab";
import { Zoom } from "@mui/material";

function CreateArea(props) {
  const [note, setNote] = useState({
    title: "",
    content: "",
  });

  let [isEditing, setIsEditing] = useState(false);

  function handleEditing() {
    setIsEditing(true);
  }

  function handleChange(event) {
    const { name, value } = event.target;

    setNote((prevNote) => {
      return {
        ...prevNote,
        [name]: value,
      };
    });
  }

  function submitNote(event) {
    if (note.title || note.content) {
      props.onAdd(note);
    }

    setNote({
      title: "",
      content: "",
    });
    setIsEditing(false);
    event.preventDefault();
  }

  return (
    <div>
      <form className="create-note">
        {isEditing && (
          <input
            name="title"
            onChange={handleChange}
            value={note.title}
            placeholder="Title"
            maxLength={20}
          />
        )}
        <textarea
          name="content"
          onClick={handleEditing}
          onChange={handleChange}
          value={note.content}
          placeholder="Take a note..."
          rows={isEditing == true ? 3 : 1}
        />
        <Zoom in={isEditing == true ? true : false} timeout={750}>
          <Fab onClick={submitNote}>
            <AddIcon />
          </Fab>
        </Zoom>
      </form>
    </div>
  );
}

export default CreateArea;
