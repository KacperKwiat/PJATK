<?php
$dbuser = 'root';
$dbpass = '';
$db = new PDO("mysql:host=localhost;dbname=projekt", $dbuser,$dbpass) or die ("Wywaliłem sie");

if(isset($_POST['login'])){
    $login=$_POST['login'];
    $password=$_POST['password'];
    $result=$db->query("select *from logins where login ='$login'");

    if($result->fetchColumn()==0){
        $Nsql="INSERT INTO `logins` (`id`, `login`, `password`) VALUES (NULL, '$login', '$password')";
        $db->query($Nsql);
        $accNum=null;
        do{
            for($i=0;$i<26;$i++){
                $Num=rand(1,9);
                $accNum .=$Num;
            }
        }while($db->query("select * from account where number='$accNum' ")==0);


        $result=$db->query("select id from logins where login='$login'");
        $id=$result->fetch(PDO::FETCH_OBJ);
        $user=0;
        foreach ($id as $value){
            $user=$value;
        }
        $sql_2="INSERT INTO `account` (`id`, `number`, `money_amount`,`logins_fk` ) VALUES (NULL, '$accNum', 50, '$user')";
        $db->query($sql_2);
        header("Location: bank/account.php");

    }else{
        echo "Chosen login name is already taken";
    }
}else{
    echo "None data was recived";
}

?>