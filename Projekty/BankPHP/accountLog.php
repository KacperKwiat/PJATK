<?php
session_start();
$dbuser = 'root';
$dbpass = '';
$db = new PDO("mysql:host=localhost;dbname=projekt", $dbuser,$dbpass) or die ("Unsuccessfulconnection");?>
<body>
<center>


<?php

if(isset($_POST['submit'])){
    $login=$_POST['login'];
    $password=$_POST['password'];
    $sql="select *from logins where login ='$login' AND password ='$password'";
    $result=$db->query($sql);?>
    <a href="logout.php" style="position:absolute; top:0; right:0" ><button>Log out</button></a>
    <?php
    if($result->rowCount()==1){
        $result=$db->query("select id from logins where login='$login'");
        $id=$result->fetch(PDO::FETCH_OBJ);
        $user=0;
        foreach ($id as $value){
            $user=$value;
        }
        $sql_3="Select number from account where logins_fk='$user'";
        $num=$db->query($sql_3);
        $number=$num->fetch(PDO::FETCH_OBJ);

        $accountNumber=0;
        foreach ($number as $acc){
            $accountNumber= $acc;

        }

        echo "Your bank account number is ".$accountNumber.'<br>';
        $sql_4="Select money_amount from account where logins_fk='$user'";
        $m=$db->query($sql_4);
        $amount=$m->fetch(PDO::FETCH_OBJ);
        $money=0;
        foreach ($amount as $mon){
            $money= $mon;

        }
        echo "Your bank balance is ".$money.' PLN'.'<br>';?>
        <a href="transferForm.php"><button>Make transfer</button></a>&nbsp;&nbsp;<?php

    }else{
        echo "You have entered wrong password or login";
        header("refresh:1;url=LoginForm.php");
    }
}else{
    echo "None data was recived";
    header("refresh:1;url=LoginForm.php");
}

?>
<a href="opinion_form.php"><button>Share opinion</button></a>
</center>
</body>
