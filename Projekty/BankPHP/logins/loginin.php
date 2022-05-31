<?php


$connect= mysqli_connect("127.0.0.1","root","","projekt");

if(isset($_POST['login'])){
    $login=$_POST['login'];
    $password=$_POST['password'];
    $sql="select *from logins where login ='$login' AND password ='$password'";
    $result=mysqli_query($connect,$sql);
    if(mysqli_num_rows($result)==1){
        echo "You did it";
    }else{
        echo "You have entered wrong password or login";
    }
}else{
    echo "Nie przeslano zadnych danych";
}


?>