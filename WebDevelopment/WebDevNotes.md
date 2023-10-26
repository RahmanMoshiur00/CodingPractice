# Web Development Notes [Ctrl+K V]

## HTML
* HTML tags, elements, boilerplate

## CSS
### Types of invoking CSS files:  
* Inline  
```html
<h1 style="color: blue"> ... </h1>
```
* Internal
```html
<head>
    <style>
        h1{
            color: red;
        }
    </style>
</head>
<! Note: style can be added anywhere in a html file>
```
* External  
```html
<!html file>
<head>
  <link rel="stylesheet" href="./style.css" />
</head>

<!CSS file: style.css>
body{
  text-align: center;
}
```

### Types of CSS selectors:  
* Element Selector: 
```html
h1{ color: red; }
```  
* Class Selector:  
```html
1.
<h1 class="new_header">
<!CSS>
.new_header{ color: yellow; }

2.
<h1 id="new_id">
<!CSS>
#new_id{ color: green; }
```  
* Attribute Selector:
```html
<li class="note" value="4">
<!CSS>
li[value="4"] {
  color: blue;
}
```

### Font Size
* 1px = 1/96th inch  
* 1pt = 1/72th inch  
* 1em = 100% of parent  
* 1rem = 100 of root

### CSS Cascade Priority Order

#### Position
1. lower (highest)
2. upper (lowest)

#### Specificity Order
1. id (highest) e.g. #first_id
2. attribute e.g. li[draggable]
3. class e.g. .first_clas
4. element (lowest) e.g. li

#### Type
1. inline (highest) e.g. ```<h1 style="..."> Hello </h1>```
2. internal e.g. ```<style> ... </style>```
3. external (lowest) e.g. ```<link rel="stylesheet" href="./style.css">```

#### Importance
1. important e.g.  
```h
color: red;
color: green !important; // most important rule, it will be applied
```

### Combining CSS Selectors
1. Grouping.
```html
h1, h2, .new_class, #new_id { }
```
2. Child.
```h
.box > p { } //selects only immediate child p tags of box class
```
3. Descendant.
```h
.box p { } //selects all descendant p tags of box class
```
4. Chaining.
```html
h1#title.big.heading{ } //CSS, selects exactly matched html element(s)
//note: start with tag element if any
<h1 id="title" class="big heading">Hello World!</h1>
```

### CSS Positioning
[How CSS Position property works?](https://www.freecodecamp.org/news/css-position-property-explained/)
1. static (default)
2. relative [parent]
3. absolute [child]
4. fixed [fixed to the display position]
5. sticky 




