
# Question

# Solutions

- Player will have to go to the bottom of the page and get to the admin profile, which have the first clue

```
Simplicity is my style; even my password bows to the charm of my favourite fruit.
```

- which signal the admin password is one of his fav fruit
- Player can go to html and find the id fav-fruit which is Buah Ciku
- with the username is from the footer and password the fruit name in scientific form

```
username = coolAdmin@fruitScope.com
password = Manilkara zapota
```

- The user then can go to robots.txt to find the hidden API which is /flag

- Player have to use postman to use get method on the /flag, which will required forbidden, user then need to include header authorization token from the login token,

- to get the token, player have to post to /auth/login following

```json
{
	"username" : "coolAdmin@fruitScope.com",
	"password" : "Manilkara zapota"

}
```
- and will receive following response

```json
{
    "username": "coolAdmin@fruitScope.com",
    "message": "Login successful",
    "token": "M_YByivKFlJG1wo2BEvVIvsrHoINjajGdoW3N-PZJYQ",
    "type": "Bearer"
}
```

- With this player can take the token and use it as header on get /flag and will get flag as response

```
IHT{C00l_U$3r_Fl@g$_@r3_@w3$0m3!}
```