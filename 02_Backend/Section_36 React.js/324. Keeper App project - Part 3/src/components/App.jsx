import React from "react";
import Header from "./Header";
import Footer from "./Footer";
import Note from "./Note";
import CreateArea from "./CreateArea";

function App() {
  let [notes, setNotes] = React.useState([]);

  function addNote(title, content) {
    notes = [...notes, { title: title, content: content }];
    setNotes(notes);
    console.log(notes);
  }

  function deleteNote(id) {
    console.log("Delete note: " + id);
    setNotes(
      notes.filter((note, index) => {
        return index != id;
      })
    );
  }

  return (
    <div>
      <Header />
      <CreateArea onAddNote={addNote} />
      <div className="notes">
        {notes.map((note, index) => {
          return (
            <Note
              key={index}
              id={index}
              onDelete={deleteNote}
              title={note.title}
              content={note.content}
            />
          );
        })}
      </div>
      <Footer />
    </div>
  );
}

export default App;
