// Add an event listener to execute code when the DOM content is loaded
document.addEventListener('DOMContentLoaded', function(){

    // Add an event listener to the form's submit event
    document.querySelector('form').addEventListener('submit', function(event){

        // Retrieve the value entered in the 'name' input field
        let name = document.querySelector('#name').value;

        // Display an alert message using the retrieved name
        alert('hello, ' + name);

        // Prevent the form from performing its default submission behavior
        event.preventDefault();
    });
});
