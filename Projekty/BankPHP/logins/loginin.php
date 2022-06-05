<?php
$dbuser = 'root';
$dbpass = '';
$db = new PDO("mysql:host=localhost;dbname=projekt", $dbuser,$dbpass) or die ("Unsuccessfulconnection");

if(isset($_POST['submit'])){
    $login=$_POST['login'];
    $password=$_POST['password'];
    $sql="select *from logins where login ='$login' AND password ='$password'";
    $result=$db->query($sql);
    if($result->rowCount()==1){
        header("Location: bank/account.php");
    }else{
        echo "You have entered wrong password or login";
    }
}else{
    echo "None data was recived";
}

?>