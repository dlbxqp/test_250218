{
    const popup = document.querySelector('#object-popup')
    const objects = document.querySelectorAll('.list__item')

    const showPopup = (objectId) => {
        fetch(`/admin?object_id=` + objectId)
            .then(response => response.json())
            .then((response) => {
                popup.querySelector('#object-id').value = response.id
                popup.querySelector('#object-title').value = response.title
                popup.querySelector('#object-description').value = response.description

                const parent = popup.querySelector('#object-parent')
                const parentId = response.parent
                fetch(`/admin?select_id=` + response.id)
                    .then(response => response.json())
                    .then((response) => {
                        Array.from(response).forEach((selectItem) => {
                            const option = document.createElement('option')
                            option.value = selectItem.id
                            option.textContent = selectItem.title
                            if (selectItem.id === parentId) option.setAttribute('selected', 'selected')

                            parent.append(option)
                        })
                    })
                    .catch((error) => {
                        return error
                    })
            })
            .catch((error) => console.log('error', error))

        !popup.classList.contains('active') && popup.classList.add('active')
    }
    const hidePopup = () => {
        popup.querySelector('#popup-form').reset()
        popup.classList.contains('active') && popup.classList.remove('active')
    }

    const deleteObject = (id) => {
        let currentObject = null
        Array.from(objects).forEach((object) => {
            if(object.querySelector('.actions__delete').dataset.id === id) currentObject = object
        })
        const childs = (currentObject) ? currentObject.querySelectorAll('.actions__delete') : {}
        Array.from(childs).forEach((child) => {
            fetch(`/admin?deleted_id=` + child.dataset.id)
            .then(() => document.location.reload())
            .catch((error) => {
                return error
            })
        })

        return true;
    }

    Array.from(objects).forEach((object) => {
        object.querySelector('.actions__edit').addEventListener('click', (e) => {
            e.preventDefault()

            showPopup(e.target.dataset.id)
        })

        object.querySelector('.actions__delete').addEventListener('click', (e) => {
            e.preventDefault()

            deleteObject(e.target.dataset.id)
        })
    })

    popup.querySelector('#popup-close').addEventListener('click', (e) => {
        e.preventDefault()

        hidePopup()
    })

    popup.querySelector('#popup-save').addEventListener('click', (e) => {
        e.preventDefault()

        fetch('/admin/index.php', {
            method: 'post',
            body: JSON.stringify({
                'id': popup.querySelector('#object-id').value,
                'title': popup.querySelector('#object-title').value,
                'description': popup.querySelector('#object-description').value,
                'parent': popup.querySelector('#object-parent').value
            })
        })
            .then((response) => document.location.reload())
            .catch((error) => console.log('error', error))
    })
}