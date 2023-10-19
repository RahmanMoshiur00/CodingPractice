# Web Development Notes

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

