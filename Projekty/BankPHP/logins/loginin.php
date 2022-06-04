<?php


$connect= mysqli_connect("127.0.0.1","root","","projekt");

if(isset($_POST['login'])){
    $login=$_POST['login'];
    $password=$_POST['password'];
    $sql="select *from logins where login ='$login' AND password ='$password'";
    $result=mysqli_query($connect,$sql);
    if(mysqli_num_rows($result)==1){
        header("Location: bank/account.php");
    }else{
        echo "You have entered wrong password or login";
    }
}else{
    echo "None data was recived";
}

?>