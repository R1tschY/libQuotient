/******************************************************************************
 * THIS FILE IS GENERATED - ANY EDITS WILL BE OVERWRITTEN
 */

#pragma once

#include "converters.h"

#include "jobs/basejob.h"

#include <QtCore/QVector>

namespace Quotient
{

// Operations

/// Searches the user directory.
/*!
 * Performs a search for users on the homeserver. The homeserver may
 * determine which subset of users are searched, however the homeserver
 * MUST at a minimum consider the users the requesting user shares a
 * room with and those who reside in public rooms (known to the homeserver).
 * The search MUST consider local users to the homeserver, and SHOULD
 * query remote users as part of the search.
 *
 * The search is performed case-insensitively on user IDs and display
 * names preferably using a collation determined based upon the
 * ``Accept-Language`` header provided in the request, if present.
 */
class SearchUserDirectoryJob : public BaseJob
{
public:
    // Inner data structures

    /// Performs a search for users on the homeserver. The homeserver
    /// maydetermine which subset of users are searched, however the
    /// homeserverMUST at a minimum consider the users the requesting user
    /// shares aroom with and those who reside in public rooms (known to the
    /// homeserver).The search MUST consider local users to the homeserver, and
    /// SHOULDquery remote users as part of the search.The search is performed
    /// case-insensitively on user IDs and displaynames preferably using a
    /// collation determined based upon the ``Accept-Language`` header provided
    /// in the request, if present.
    struct User
    {
        /// The user's matrix user ID.
        QString userId;
        /// The display name of the user, if one exists.
        QString displayName;
        /// The avatar url, as an MXC, if one exists.
        QString avatarUrl;
    };

    // Construction/destruction

    /*! Searches the user directory.
     * \param searchTerm
     *   The term to search for
     * \param limit
     *   The maximum number of results to return. Defaults to 10.
     */
    explicit SearchUserDirectoryJob(const QString& searchTerm,
                                    Omittable<int> limit = none);

    ~SearchUserDirectoryJob() override;

    // Result properties

    /// Ordered by rank and then whether or not profile info is available.
    const QVector<User>& results() const;
    /// Indicates if the result list has been truncated by the limit.
    bool limited() const;

protected:
    Status parseJson(const QJsonDocument& data) override;

private:
    class Private;
    QScopedPointer<Private> d;
};

} // namespace Quotient
