document.addEventListener('DOMContentLoaded', function(){

    document.querySelector('form').addEventListener('submit', funtion(event){

        let name = document.querySelector('#name'.value);
        alert('hello, ' + name);
        event.preventDefault();
    });
});