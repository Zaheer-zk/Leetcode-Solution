/**
 * @param {string[]} emails
 * @return {number}
 */
var numUniqueEmails = function(emails) {
    const uniqueEmails = new Set();

    emails.forEach((email) => {
        let [localName, domainName] = email.split('@');
        console.log(localName, domainName);

        localName = localName.replace(/\./g, '');

        if(localName.includes('+')) {
            localName = localName.slice(0, localName.indexOf('+'));
        }

        email = `${localName}@${domainName}`;
        console.log(email)

        uniqueEmails.add(email);
    })
    console.log(uniqueEmails.size)
    return uniqueEmails.size;
};